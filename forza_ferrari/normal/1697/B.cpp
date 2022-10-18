#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int t,n,m,a[200001];
signed main()
{
    t=1;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        sort(a+1,a+n+1,greater<int>());
        for(int i=2;i<=n;++i)
            a[i]+=a[i-1];
        while(m--)
        {
            int x,y;
            cin>>x>>y;
            cout<<a[x]-a[x-y]<<'\n';
        }
    }
    return 0;
}