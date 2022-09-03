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
#define last Last
#define MAXK 2500
LL dp[405][405][2];
int val[405];
int mod;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
LL dp2[405][405];
LL fra[405],inv[405];
void solve(){
    
    int n;
    scanf("%d %d",&n,&mod);
    fra[0]=1;
    for(int i = 1;i<=n;i++)fra[i]=fra[i-1]*i%mod;
    inv[n]=f_pow(fra[n],mod-2);
    for(int i = n-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
    dp[2][1][0]=1;
    dp[2][2][1]=1;
    val[1]=1;
    val[2]=2;
    for(int i = 3;i<=n;i++){
        int tot=0;
        for(int j=1;j<=i;j++){
            for(int k = 1;k<i;k++){
                if(k>=j){
                    dp[i][j][0]+=dp[i-1][k][0]%mod;
                    dp[i][j][0]%=mod;
                }
                else{
                    dp[i][j][1]+=dp[i-1][k][0]+dp[i-1][k][1];
                    dp[i][j][1]%=mod;
                  
                }
           //     tot%=mod;
            }
              tot+=dp[i][j][0];
              tot%=mod;
                tot+=dp[i][j][1];
            tot%=mod;
        }
        val[i]=tot;
      //  printf("%d ",val[i]);
    }
  //  printf("\n");
    dp2[0][0]=1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=i;j++){
            for(int k = 1;k<=j;k++){
                if(i==k)
                dp2[i][j]+=val[k]*inv[k]%mod;
                else{
                    if(i-k-1!=0)
                    dp2[i][j]+=dp2[i-k-1][j-k]*inv[k]%mod*val[k]%mod;;
                }
                dp2[i][j]%=mod;
            }
          //  printf("%d  %d %d\n",i,j,dp2[i][j]);
        }
    }
    LL ans=0;
    for(int i = 1;i<=n;i++)ans+=dp2[n][i]*fra[i]%mod,ans%=mod;
    printf("%lld\n",ans);
}
int main(){
  //  for(int i = 1;i*i<=1e9;i++)s.insert(i*i);
    int t=1;00000;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
36

x x<<13  x>>7  x<<13>>7
x<<17  x<<30 x>>7<<17 x<<23

*/