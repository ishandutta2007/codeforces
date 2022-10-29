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
    long n,k,i,j,a[6][1004],pos[1004][8],dp[1004],ans=0,l,ii,jj;
    cin>>n>>k;
    for(i=1;i<=k;++i)
    for(j=1;j<=n;++j)
    {
        cin>>a[i][j];
        pos[a[i][j]][i]=j;
    }
    for(i=1;i<=n;++i)
    dp[i]=1;
    for(ii=1;ii<=n;++ii)
    {
        i=a[1][ii];
        for(jj=1;jj<ii;jj++)
        {
            j=a[1][jj];
            for(l=1;l<=k;++l)
            if(pos[j][l]>pos[i][l]) break;
            if(l!=k+1) continue;
            dp[i]=max(dp[i],dp[j]+1);
        }
    }
    for(i=1;i<=n;++i)
    ans=max(ans,dp[i]);
    cout<<ans;
    return 0;
}