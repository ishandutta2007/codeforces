#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    io
    long n,a[2][55]={0},b[55],i,j,ans=1e9;
    cin>>n;
    for(i=1;i<=n-1;++i)
    {
        cin>>a[0][i];
        a[0][i]+=a[0][i-1];
    }
    for(i=1;i<=n-1;++i)
    {
        cin>>a[1][i];
        a[1][i]+=a[1][i-1];
    }
    for(i=0;i<n;++i)
    cin>>b[i];
    for(i=0;i<n;++i)
    for(j=0;j<n;++j)
    if(i!=j)
    ans=min(ans,a[0][i]+a[1][n-1]-a[1][i]+b[i]+a[0][j]+a[1][n-1]-a[1][j]+b[j]);
    cout<<ans;
    return 0;
}