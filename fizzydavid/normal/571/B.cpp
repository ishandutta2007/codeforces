//by yjz
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,k,dp[2][5011],a[300111],sum;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)a[i]=a[i+1]-a[i],sum+=a[i];a[n]=0;
    int cnt1=n%k,cnt2=k-cnt1;
    for(int i=0;i<=cnt1;i++)
    {
        int p=i&1;
        for(int j=0;j<=cnt2;j++)
        {
            dp[p][j]=0;
            if(j>0)dp[p][j]=max(dp[p][j],dp[p][j-1]);
            if(i>0)dp[p][j]=max(dp[p][j],dp[!p][j]);
            dp[p][j]+=a[i*(n/k+1)+j*(n/k)];
        }
    }
    cout<<sum-dp[cnt1&1][cnt2]<<endl;
    return 0;
}