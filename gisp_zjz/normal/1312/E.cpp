#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
int dp[505][505],ans[505],a[505],n;
int main(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) dp[i][i]=a[i];
    for (int l=n;l;l--)
    for (int r=l+1;r<=n;r++){
        for (int m=l;m<r;m++)
            if (dp[l][m]!=0&&dp[l][m]==dp[m+1][r]) dp[l][r]=dp[l][m]+1;
    }
    for (int i=1;i<=n;i++){
        ans[i]=ans[i-1]+1;
        for (int j=1;j<i;j++) if (dp[j][i]) ans[i]=min(ans[i],ans[j-1]+1);
    }
    cout << ans[n] << endl;
}