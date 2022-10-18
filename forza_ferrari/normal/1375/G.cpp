#include<iostream>
#include<cstdio>
using namespace std;
struct edge
{
    int nxt,to;
}e[200001<<1];
int n,tot,h[200001],cnt[2];
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
inline void dfs(int k,int f,bool tag)
{
    ++cnt[tag];
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs(e[i].to,k,tag^1);
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1,0,0);
    cout<<min(cnt[0],cnt[1])-1<<'\n';
    return 0;
}