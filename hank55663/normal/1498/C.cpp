#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=1e9+7;
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    int dp[2][1005];
    MEM(dp);
    dp[0][0]=1;
    LL ans=0;
    for(int i = 1;i<=k;i++){
        for(int j = 0;j<n;j++){
            ans+=dp[(i&1)^1][j];
            ans%=mod;
        }
        MEM(dp[i&1]);
        if(i&1){
            LL sum=0;
            for(int j = 0;j<n;j++){
                sum+=dp[(i&1)^1][j];
                sum%=mod;
                dp[i&1][j]=sum;
            }
        }
        else{
            LL sum=0;
            for(int j =n;j>0;j--){
                sum+=dp[(i&1)^1][j];
                sum%=mod;
                dp[i&1][j]=sum;
            }
        }
    }
    printf("%lld\n",ans);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}