#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,minn;
long long a[300001];
long long sum;
vector<pair<int,int> > v[300001];
vector<int> ans1,ans2;
bool vis[300001];
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
inline void dfs(int k)
{
    vis[k]=1;
    for(auto i:v[k])
        if(!vis[i.first])
        {
            dfs(i.first);
            if(a[i.first]>=minn)
            {
                a[k]+=a[i.first]-minn;
                ans1.emplace_back(i.second);
            }
            else
                ans2.emplace_back(i.second);
        }
}
signed main()
{
    n=read(),m=read(),minn=read();
    for(int i=1;i<=n;++i)
        sum+=a[i]=read();
    if(sum<1ll*(n-1)*minn)
    {
        cout<<"NO\n";
        return 0;
    }
    for(int i=1;i<=m;++i)
    {
        int x=read(),y=read();
        v[x].emplace_back(y,i);
        v[y].emplace_back(x,i);
    }
    cout<<"YES\n";
    dfs(1);
    reverse(ans2.begin(),ans2.end());
    for(auto i:ans1)
        cout<<i<<'\n';
    for(auto i:ans2)
        cout<<i<<'\n';
    return 0;
}