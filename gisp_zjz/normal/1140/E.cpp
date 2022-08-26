#include<bits/stdc++.h>
#define maxn 2050505
using namespace std;
typedef long long ll;
const ll M=998244353;
ll a[maxn],n,k,dp[maxn][2],nxt[maxn],p[maxn],ans,q[maxn],P,Q;
ll solve (ll *a,ll n){
    memset(dp,0,sizeof(dp));
    nxt[n+1]=n+1;
    for (int i=n;i;i--) nxt[i]=(a[i]==-1)?nxt[i+1]:i;
    //dp[0][0]=1;
    if (a[1]==-1&&nxt[1]!=n+1) dp[1][0]=k-1,dp[1][1]=1;
    else if (a[1]==-1) dp[1][0]=k;
    else dp[1][a[1]==a[nxt[2]]]=1;
    for (int i=2;i<=n;i++) {
        if (a[i]!=-1){
            dp[i][a[i]==a[nxt[i+1]]]=dp[i-1][0];
        } else if (a[nxt[i]]){
            dp[i][1]=dp[i-1][0];
            dp[i][0]=(dp[i-1][0]*(k-2)+dp[i-1][1]*(k-1))%M;
        } else {
            dp[i][0]=dp[i-1][0]*(k-1)%M;
            dp[i][1]=dp[i-1][1]*(k-1)%M;
        }
    }
    //cout<<(dp[n][0]+dp[n][1])%M<<endl;
    return (dp[n][0]+dp[n][1])%M;
}

int main(){
    cin >> n >> k;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        if (i&1) p[++P]=a[i];
        else q[++Q]=a[i];
    }
    cout << solve(p,P)*solve(q,Q)%M << endl;
}