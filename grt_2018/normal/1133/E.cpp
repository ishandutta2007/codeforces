#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5001;

int n,k;
int a[MAXN];
int cnt[MAXN];
int dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1; i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int wsk = 1;
    for(int i=1; i<=n;i++) {
        while(wsk<=i&&a[i] - a[wsk]>5)
            wsk++;
        cnt[i] = i-wsk+1;
    }
    for(int i=1; i<=n;i++) {
        for(int j=1; j<=k;j++) {
            dp[i][j] = max(dp[i-1][j],dp[i-cnt[i]][j-1]+cnt[i]);
        }
    }
    cout<<dp[n][k];
    return 0;
}