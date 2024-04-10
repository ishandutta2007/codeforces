#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
struct edge
{
    int nxt,to;
}e[200001<<1];
int n,m,tot,h[200001<<1],cnt,lst,link[200001<<1],ch[200001<<1][26],len[200001<<1],s[200001<<1][2],fa[200001<<1][21],dep[200001<<1],dfn[200001<<1],id,num[200001],top,t[200001],q[200001<<1];
long long ans;
string str;
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline bool cmp(int x,int y)
{
    return dfn[x]<dfn[y];
}
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
inline void build(int c)
{
    int cur=++cnt,p=lst;
    len[cur]=len[lst]+1;
    lst=cur;
    for(;~p;p=link[p])
        if(!ch[p][c])
            ch[p][c]=cur;
        else
            break;
    if(p==-1)
        return;
    int q=ch[p][c];
    if(len[p]+1==len[q])
    {
        link[cur]=q;
        return;
    }
    int clone=++cnt;
    link[clone]=link[q];
    len[clone]=len[p]+1;
    for(int i=0;i<26;++i)
        ch[clone][i]=ch[q][i];
    link[cur]=link[q]=clone;
    for(;~p;p=link[p])
        if(ch[p][c]==q)
            ch[p][c]=clone;
        else
            break;
}
inline void dfs1(int k,int f,int deep)
{
    dep[k]=deep;
    fa[k][0]=f;
    dfn[k]=++id;
    for(int i=1;i<=20;++i)
        fa[k][i]=fa[fa[k][i-1]][i-1];
    for(int i=h[k];i;i=e[i].nxt)
        dfs1(e[i].to,k,deep+1);
}
inline int LCA(int x,int y)
{
    if(dep[x]<dep[y])
        x^=y^=x^=y;
    for(int d=dep[x]-dep[y],i=0;1<<i<=d;++i)
        if(d&(1<<i))
            x=fa[x][i];
    if(x==y)
        return x;
    for(int i=20;~i;--i)
        if(fa[x][i]^fa[y][i])
        {
            x=fa[x][i];
            y=fa[y][i];
        }
    return fa[x][0];
}
inline void dfs2(int k,int f)
{
    for(int i=h[k];i;i=e[i].nxt)
    {
        dfs2(e[i].to,k);
        s[k][0]+=s[e[i].to][0];
        s[k][1]+=s[e[i].to][1];
    }
    if(k)
        ans+=1ll*s[k][0]*s[k][1]*(len[k]-len[f]);
}
inline void dfs3(int k)
{
    for(int i=h[k];i;i=e[i].nxt)
        dfs3(e[i].to);
    h[k]=s[k][0]=s[k][1]=0;
}
int main()
{
    n=read(),m=read();
    cin>>str;
    link[0]=-1;
    for(int i=n-1;~i;--i)
    {
        build(str[i]-'a');
        num[i+1]=lst;
    }
    for(int i=1;i<=cnt;++i)
    {
        add(link[i],i);
        //cout<<link[i]<<" "<<i<<'\n';
    }
    dfs1(0,-1,1);
    dfs3(0);
    tot=0;
    while(m--)
    {
        int p1=read(),p2=read();
        t[top=1]=0;
        for(int i=1;i<=p1;++i)
            ++s[q[i]=num[read()]][0];
        for(int i=1;i<=p2;++i)
            ++s[q[i+p1]=num[read()]][1];
        sort(q+1,q+p1+p2+1,cmp);
        q[0]=0;
        for(int i=1;i<=p1+p2;++i)
        {
            if(q[i]==q[i-1])
                continue;
            int lca=LCA(t[top],q[i]);
            if(lca!=t[top])
            {
                while(dfn[lca]<dfn[t[top-1]])
                {
                    add(t[top-1],t[top]);
                    --top;
                }
                if(lca!=t[top-1])
                {
                    add(lca,t[top]);
                    t[top]=lca;
                }
                else
                    add(lca,t[top--]);
            }
            t[++top]=q[i];
        }
        while(top>1)
        {
            add(t[top-1],t[top]);
            --top;
        }
        ans=0;
        dfs2(0,0);
        cout<<ans<<'\n';
        dfs3(0);
        tot=0;
    }
    return 0;
}