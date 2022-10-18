#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,t,T,a,b,l[100001],r[100001],col[100001];
vector<int> v[100001];
bool vis[100001];
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
inline bool dfs(int k,int tag)
{
    if(col[k])
        if(col[k]^tag)
            return 0;
    if(vis[k])
        return 1;
    vis[k]=1;
    col[k]=tag;
    for(int i:v[k])
        if(!dfs(i,3-tag))
            return 0;
    return 1;
}
int main()
{
    t=read(),a=T=read(),n=read(),m=read();
    for(int i=1;i<=n;++i)
        b=max(b,l[i]=read()),a=min(a,r[i]=read());
    if(a+b<t)
        b=t-a;
    if(a+b>T)
        a=T-b;
    if(a<0||b<0)
    {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    for(int i=1;i<=n;++i)
    {
        bool flag1=l[i]<=a&&r[i]>=a,flag2=l[i]<=b&&r[i]>=b;
        if(!flag1&&!flag2)
        {
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
        if(!flag1)
            col[i]=2;
        if(!flag2)
            col[i]=1;
    }
    for(int i=1;i<=m;++i)
    {
        int x=read(),y=read();
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }
    for(int i=1;i<=n;++i)
        if(col[i]&&!vis[i])
            if(!dfs(i,col[i]))
            {
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
    for(int i=1;i<=n;++i)
        if(!vis[i])
            if(!dfs(i,1))
            {
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
    cout<<"POSSIBLE\n"<<a<<" "<<b<<'\n';
    for(int i=1;i<=n;++i)
        cout<<col[i];
    cout<<'\n';
    return 0;
}