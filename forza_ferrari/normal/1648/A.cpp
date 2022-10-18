#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
int n,m,ans;
vector<int> v[100001<<1];
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            int x;
            cin>>x;
            v[(x<<1)-1].emplace_back(i);
            v[x<<1].emplace_back(j);
        }
    for(int i=1;i<=200000;++i)
    {
        sort(v[i].begin(),v[i].end());
        int a=0,b=0;
        for(int j:v[i])
        {
            ans+=j*(b++)-a;
            a+=j;
        }
    }
    cout<<ans<<'\n';
    return 0;
}