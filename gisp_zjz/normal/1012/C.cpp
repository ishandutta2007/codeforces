#include<bits/stdc++.h>
#define maxn 2304939

using namespace std;
const int inf=2e9;
int dp[5005][2505][3],n,a[maxn],p,q;
int main(){
    cin >> n;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=0;i<=n;i++)
        for (int j=0;j<=(n+1)/2;j++)
            dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=inf;
    dp[0][0][0]=0;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=(i+1)/2;j++){
            dp[i][j][1]=dp[i-1][j][2];
            dp[i][j][0]=min(dp[i-1][j][0],dp[i-1][j][1]);
            if (j) {
                p=dp[i-1][j-1][0]+max(a[i-1]-a[i]+1,0);
                if (j>1) p=min(p,dp[i-1][j-1][1]+max(min(a[i-2]-1,a[i-1])-a[i]+1,0));
                dp[i][j][2]=p+max(a[i+1]-a[i]+1,0);
            } else dp[i][j][2]=inf;
        }
    for (int i=1;i<=(n+1)/2;i++)
        cout << min(min(dp[n][i][0],dp[n][i][1]),dp[n][i][2]) << ' ';
    cout << endl;
    return 0;
}