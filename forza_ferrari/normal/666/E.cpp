#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
using namespace std;
string s,t[50001];
int n,m,q,ch[600001<<1][26],len[600001<<1],link[600001<<1],pos[500001],fa[600001<<1][21],tot,cnt,ls[600001*30],rs[600001*30],maxn[600001*30],num[600001*30],root[600001<<1];
pair<int,int> ans[500001];
struct element
{
    int l,r,id;
    element(int l_,int r_,int id_):
        l(l_),r(r_),id(id_){}
};
vector<element> v[600001<<1];
vector<int> g[600001<<1];
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
inline void push_up(int k)
{
    if(maxn[ls[k]]>=maxn[rs[k]])
    {
        maxn[k]=maxn[ls[k]];
        num[k]=num[ls[k]];
    }
    else
    {
        maxn[k]=maxn[rs[k]];
        num[k]=num[rs[k]];
    }
    //cout<<k<<" "<<maxn[k]<<" "<<num[k]<<'\n';
}
inline int merge(int x,int y,int l,int r)
{
    if(!x||!y)
        return x|y;
    if(l==r)
    {
        maxn[x]+=maxn[y];
        return x;
    }
    int mid=(l+r)>>1;
    if(ls[y])
        if(ls[x])
            ls[x]=merge(ls[x],ls[y],l,mid);
        else
            ls[x]=ls[y];
    if(rs[y])
        if(rs[x])
            rs[x]=merge(rs[x],rs[y],mid+1,r);
        else
            rs[x]=rs[y];
    push_up(x);
    return x;
}
inline void update(int node,int l,int r,int &k)
{
    if(!k)
        k=++cnt;
    if(l==r)
    {
        ++maxn[k];
        num[k]=node;
        //cout<<k<<" "<<maxn[k]<<" "<<num[k]<<'\n';
        return;
    }
    int mid=(l+r)>>1;
    if(node<=mid)
        update(node,l,mid,ls[k]);
    else
        update(node,mid+1,r,rs[k]);
    push_up(k);
}
inline pair<int,int> query(int nl,int nr,int l,int r,int k)
{
    if(!k)
        return {0,max(nl,l)};
    if(l>=nl&&r<=nr)
        return {maxn[k],num[k]};
    int mid=(l+r)>>1;
    if(nr<=mid)
        return query(nl,nr,l,mid,ls[k]);
    if(nl>mid)
        return query(nl,nr,mid+1,r,rs[k]);
    pair<int,int> ql=query(nl,nr,l,mid,ls[k]),qr=query(nl,nr,mid+1,r,rs[k]);
    if(ql.first>=qr.first)
        return ql;
    return qr;
}
inline void insert(int x)
{
    int node=0;
    for(auto i:t[x])
    {
        if(!ch[node][i-'a'])
            ch[node][i-'a']=++tot;
        node=ch[node][i-'a'];
        update(x,1,m,root[node]);
    }
    return;
}
inline int build(int lst,int c)
{
    int cur=ch[lst][c],p=link[lst];
    len[cur]=len[lst]+1;
    for(;~p;p=link[p])
        if(!ch[p][c])
            ch[p][c]=cur;
        else
            break;
    if(p==-1)
        return cur;
    int q=ch[p][c];
    if(len[p]+1==len[q])
    {
        link[cur]=q;
        return cur;
    }
    int clone=++tot;
    len[clone]=len[p]+1;
    link[clone]=link[q];
    for(int i=0;i<26;++i)
        if(len[ch[q][i]])
            ch[clone][i]=ch[q][i];
    link[q]=link[cur]=clone;
    for(;~p;p=link[p])
        if(ch[p][c]==q)
            ch[p][c]=clone;
        else
            break;
    return cur;
}
inline void bfs()
{
    queue<pair<int,int> > q;
    link[0]=-1;
    for(int i=0;i<26;++i)
        if(ch[0][i])
            q.emplace(0,i);
    while(!q.empty())
    {
        pair<int,int> k=q.front();
        q.pop();
        int node=build(k.first,k.second);
        for(int i=0;i<26;++i)
            if(ch[node][i])
                q.emplace(node,i);
    }
}
inline void dfs1(int k,int f)
{
    fa[k][0]=f;
    for(int i=1;i<=20;++i)
        fa[k][i]=fa[fa[k][i-1]][i-1];
    for(int i:g[k])
        dfs1(i,k);
}
inline void dfs2(int k)
{
    for(int i:g[k])
    {
        dfs2(i);
        root[k]=merge(root[k],root[i],1,m);
    }
    for(auto i:v[k])
        ans[i.id]=query(i.l,i.r,1,m,root[k]);
}
int main()
{
    cin>>s;
    n=s.length();
    int node=0;
    for(int i=0;i<n;++i)
    {
        if(!ch[node][s[i]-'a'])
            ch[node][s[i]-'a']=++tot;
        pos[i+1]=node=ch[node][s[i]-'a'];
    }
    m=read();
    for(int i=1;i<=m;++i)
    {
        cin>>t[i];
        insert(i);
    }
    bfs();
    for(int i=1;i<=tot;++i)
        g[link[i]].emplace_back(i);
    dfs1(0,0);
    q=read();
    for(int i=1;i<=q;++i)
    {
        int l=read(),r=read(),pl=read(),pr=read(),k=pos[pr];
        for(int j=20;~j;--j)
            if(len[fa[k][j]]>=pr-pl+1)
                k=fa[k][j];
        v[k].emplace_back(l,r,i);
    }
    dfs2(0);
    for(int i=1;i<=q;++i)
        cout<<ans[i].second<<" "<<ans[i].first<<'\n';
    return 0;
}