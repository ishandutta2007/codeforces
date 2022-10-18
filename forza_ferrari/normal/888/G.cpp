#include<iostream>
#include<cstdio>
using namespace std;
int n,tot=1,ch[200001*30][2];
long long ans;
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
inline void insert(int x)
{
    int node=1;
    for(int i=30;~i;--i)
    {
        if(!ch[node][(x>>i)&1])
            ch[node][(x>>i)&1]=++tot;
        node=ch[node][(x>>i)&1];
    }
}
inline int query(int x,int y,int dep)
{
    if(dep<0)
        return 0;
    if(ch[x][0]&&ch[y][0]&&ch[x][1]&&ch[y][1])
        return min(query(ch[x][0],ch[y][0],dep-1),query(ch[x][1],ch[y][1],dep-1));
    if(ch[x][0]&&ch[y][0])
        return query(ch[x][0],ch[y][0],dep-1);
    if(ch[x][1]&&ch[y][1])
        return query(ch[x][1],ch[y][1],dep-1);
    if(ch[x][0]&&ch[y][1])
        return query(ch[x][0],ch[y][1],dep-1)|(1<<dep);
    return query(ch[x][1],ch[y][0],dep-1)|(1<<dep);
}
inline void dfs(int node,int dep)
{
    if(dep<0)
        return;
    if(ch[node][0]&&ch[node][1])
        ans+=query(ch[node][0],ch[node][1],dep-1)|(1<<dep);
    if(ch[node][0])
        dfs(ch[node][0],dep-1);
    if(ch[node][1])
        dfs(ch[node][1],dep-1);
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
        insert(read());
    dfs(1,30);
    cout<<ans<<endl;
    return 0;
}