#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct edge
{
    int nxt,to,weight;
}e[300001<<1];
int n,m,tot,h[300001],d[300001],root,sum,bin[300001];
vector<int> ans;
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline int anc(int k)
{
    if(!bin[k])
        return k;
    return bin[k]=anc(bin[k]);
}
inline void link(int x,int y)
{
    x=anc(x);
    y=anc(y);
    if(x^y)
        bin[y]=x;
}
inline void add(int x,int y,int w)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
    e[tot].weight=w;
}
inline bool dfs(int k,int f,int w)
{
    bool flag=0;
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        flag^=dfs(e[i].to,k,e[i].weight);
    }
    if(k!=root&&d[k]!=-1&&flag!=d[k])
    {
        ans.emplace_back(w);
        return 1;
    }
    return 0;
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
        if((d[i]=read())==-1)
            root=i;
        else
            sum+=d[i];
    for(int i=1;i<=m;++i)
    {
        int x=read(),y=read();
        if(anc(x)^anc(y))
        {
            add(x,y,i);
            add(y,x,i);
            link(x,y);
        }
    }
    if(!root&&(sum&1))
    {
        puts("-1");
        return 0;
    }
    if(!root)
        root=1;
    dfs(root,0,0);
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(auto i:ans)
        cout<<i<<'\n';
    return 0;
}