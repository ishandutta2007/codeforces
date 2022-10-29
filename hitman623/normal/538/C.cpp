#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pair < long , long > pll
using namespace std;

int main()
{
    long n,m,d[100005],h[100005],i,ans=0,x;
    cin>>n>>m;
    for(i=1;i<=m;++i)
    cin>>d[i]>>h[i];
    d[0]=1;h[0]=h[1]+d[1]-1;
    d[m+1]=n;h[m+1]=h[m]+n-d[m];
    for(i=0;i<=m;++i)
    if(h[i+1]>h[i])
    {
        if(h[i+1]-h[i]>d[i+1]-d[i]) {cout<<"IMPOSSIBLE";exit(0);}
        x=d[i+1]-d[i]-(h[i+1]-h[i]);
        ans=max(ans,h[i+1]+x/2);
    }
    else
    {
        if(h[i]-h[i+1]>d[i+1]-d[i]) {cout<<"IMPOSSIBLE";exit(0);}
        x=d[i+1]-d[i]-(h[i]-h[i+1]);
        ans=max(ans,h[i]+x/2);
    }
    cout<<ans<<endl;
    return 0;
}