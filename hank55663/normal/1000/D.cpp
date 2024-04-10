#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int mod = 998244353;
LL C[1005][1005];
int main(){
    MEM(C);
    for(int i=0;i<1005;i++){
        C[i][i]=1;C[i][0]=1;
    }
    for(int i=0;i<1005;i++)
        for(int j=1;j<i;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
            C[i][j]%=mod;
        }
    int n;
    scanf("%d",&n);
    int a[1005];
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    LL dp[1005];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=1;
        for(int j=1;j<i;j++){
            if(a[i-j]>0&&a[i-j]<1005){
                dp[i]+=dp[i-j-1]*C[j][a[i-j]];
             //   printf("%d ",dp[i-j-1]*C[j][a[i-j]]);
                dp[i]%=mod;
            }
        }
     //   printf("%d\n",dp[i]);
    }
    printf("%lld\n",(dp[n]+mod-1)%mod);
}