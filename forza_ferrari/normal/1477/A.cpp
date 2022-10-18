#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int t,n,m,a[200001],g;
inline int gcd(int x,int y)
{
    return x%y? gcd(y,x%y):y;
}
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        sort(a+1,a+n+1);
        g=a[2]-a[1];
        for(int i=2;i<n;++i)
            g=gcd(g,a[i+1]-a[i]);
        puts((m-a[1])%g? "NO":"YES");
    }
    return 0;
}