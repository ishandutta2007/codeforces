#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,pos[1<<13];
vector<int> v[5001];
bool vis[1<<13];
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
int main()
{
    n=read();
    for(int i=0;i<1<<13;++i)
        pos[i]=5000;
    for(int i=0;i<=5000;++i)
        v[i].emplace_back(0);
    pos[0]=-1;
    vis[0]=1;
    while(n--)
    {
        int x=read();
        for(int i=0;i<(int)v[x].size();++i)
            for(vis[v[x][i]^x]=1;pos[v[x][i]^x]>=x;--pos[v[x][i]^x])
                v[pos[v[x][i]^x]].emplace_back(v[x][i]^x);
        v[x].clear();
    }
    int ans=0;
    for(int i=0;i<1<<13;++i)
        ans+=vis[i];
    cout<<ans<<'\n';
    for(int i=0;i<1<<13;++i)
        if(vis[i])
            cout<<i<<" ";
    cout<<'\n';
    return 0;
}