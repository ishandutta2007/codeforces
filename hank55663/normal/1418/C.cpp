#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pll pair<LL,LL>
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
using namespace std;
int mod=1e9+7;
void solve(){
    int n;
    scanf("%d",&n);
    int dp[200005];
    int a[200005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    dp[0]=0;
    dp[1]=1e9;
    for(int i = 2;i<=n;i++){
        dp[i]=1e9;
        for(int j = max(i-4,0);j<=i-2;j++){
            if(j==i-4)dp[i]=min(dp[i],dp[j]+a[j+1]+a[j+2]);
            else
            dp[i]=min(dp[i],dp[j]+a[j+1]);
        }
    }
    dp[n]=min(dp[n],dp[n-1]+a[n]);
    printf("%d\n",dp[n]);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
       // printf("Case #%d: ",T++);
        solve();
    }
}