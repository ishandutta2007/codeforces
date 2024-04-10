#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int mod=1e9+7;
int main(){
    int n;
    scanf("%d",&n);
    int dp[5005];
    fill(dp,dp+5005,0);
    dp[0]=1;
    int last = 0;
    for(int i = 0;i<n;i++){
        char c;
        scanf(" %c",&c);
        if(c=='s'){
            if(last==1){
                
            }
            else{
                int sum=0;
                for(int j=5000;j>=0;j--){
                    sum+=dp[j];
                    sum%=mod;
                    dp[j]=sum;
                }
            }
            last=0;
        }
        else{
           // printf("%d\n",last);
            if(last == 1){

            }
            else{
                int sum=0;
                for(int j=5000;j>=0;j--){
                    sum+=dp[j];
                    sum%=mod;
                    dp[j]=sum;
                }
            }
            for(int j = 5000;j>0;j--){
                dp[j]=dp[j-1];
            }
            dp[0]=0;
            last = 1;
        }
    }
    LL sum=0;
    for(int j = 0;j<=5000;j++)
        sum+=dp[j];
    printf("%lld\n",sum%mod);
}