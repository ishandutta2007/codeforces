#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

constexpr int16_t N=2005;
int16_t a[N], s[N], c[N<<1];
int32_t dp[N<<1][N];

constexpr int32_t INF=1061109568;

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int16_t n, m; cin>>n>>m;
    for(int16_t i=0; i<n; i++) cin>>a[i];
    for(int16_t i=0; i<n; i++) cin>>s[i];
    for(int16_t i=1; i<=n+m; i++) cin>>c[i];
    memset(dp, 192, sizeof(dp));
    for(int16_t i=n-1; ~i; i--) {
        int16_t cnt=0;
        for(int16_t j=n-1; j; j--) if(dp[a[i]][j]!=-INF) {
            cnt=max(cnt, int16_t(j+1)); //this is fucking ridiculous
            dp[a[i]][j+1]=max(dp[a[i]][j+1], dp[a[i]][j]+c[a[i]]-s[i]);
        }
        int mx=0;
        for(int16_t j=1; j<a[i]; j++) mx=max(mx, dp[j][1]);
        dp[a[i]][1]=max(dp[a[i]][1], mx+c[a[i]]-s[i]);
        for(int j=a[i]+1; cnt>1; j++, cnt>>=1) {
            for(int16_t k=1; k<=(cnt>>1); k++) {
                dp[j][k]=max(dp[j][k], max(dp[j-1][k*2], dp[j-1][k*2+1])+c[j]*k);
            }
        }
    }
    int32_t ans=0;
    for(int16_t i=1; i<=n+m; i++) ans=max(ans, dp[i][1]);
    cout<<ans<<endl;
}