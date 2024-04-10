#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=998244353;
LL dp[255][255][255];
LL inv[255];
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 1;i<=k;i++){
        dp[2][i][1]=f_pow(k-i+1,n-2);
    }
    for(int i = 1;i<=n;i++){
        inv[i]=f_pow(i,mod-2);
    }
    for(int i = 3;i<=n;i++){
       
        for(int j = 1;j<=k;j++){
            LL val = f_pow(k-j+1,n-i);
            for(int a=2;a<=n;a++){
                dp[i][j][a]=dp[i-1][j][a-1]*val%mod*inv[a]%mod;
            }
        }
        LL sum=0;

        for(int j = k;j>=1;j--){
          
            dp[i][j][1]+=f_pow(k-j+1,n-i)*sum%mod;
            dp[i][j][1]%=mod;
            for(int a=1;a<=n;a++){
                sum+=dp[i-1][j][a];
                sum%=mod;
            }
        }
    }
    LL sum=0;
    for(int j = 1;j<=k;j++){
        for(int a=1;a<=n;a++)
        sum+=dp[n][j][a];
    }
    sum%=mod;
    for(int j = 1;j<=n-1;j++)sum=sum*j%mod;
    printf("%lld\n",sum%mod);
}


int main(){
    int t=1;
  //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/