#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
int dp[1005][1005];
int mod=998244353;
int main(){
    int n,K;
    scanf("%d %d",&n,&K);
    int a[1005];
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    LL ans[100005];
    MEM(ans);
    for(int i = 0;;i++){
        for(int j = 0;j<=n;j++){
            for(int k = 0;k<=K;k++)
                dp[j][k]=0;
            dp[j][0]=1;
        }
        for(int j = 1;j<=K;j++){
            int l=0;
            for(int  k=1;k<=n;k++){
                dp[k][j]=dp[k-1][j];
                while(a[k]-a[l+1]>=i&&l+1!=k)l++;
                dp[k][j]+=dp[l][j-1];
                dp[k][j]%=mod;
            }
        }
        if(dp[n][K]==0){
            break;
        }
        ans[i]=dp[n][K];
    }
    LL res=0,tot=0;
    for(int j =100000;j>=0;j--){
        res+=(ans[j]-tot+mod)*j%mod;
        tot=ans[j];
        tot%=mod;
       // if(ans[j])
         //   printf("%d %d\n",j,ans[j]);
    }
    printf("%lld\n",res%mod);
}