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
LL dp[2505][5005];
int val[5005];
const int mod=998244353;
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
    int n;
    scanf("%d",&n);
    for(int i = 0;i<=n/2;i++){
        for(int j = 0;j<=n;j++)dp[i][j]=0,val[j]=0;
    }
    int a[5005];
    map<int,int> m;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        m[a[i]]++;
    }
    LL fra[5005];
    fra[0]=1;
    for(int i = 1;i<=n;i++)fra[i]=fra[i-1]*i%mod;
    for(int i = 1;i<=n;i++){
        for(int j =1;j<=n;j++){
            if(a[j]<a[i])val[i]++;
        }
        val[i]++;
    }
  //  printf("0 ");
    for(int i = 2;i<=n;i++){
        if(1){
            dp[1][i]=val[i]-1;
        }
        //printf("%d ",dp[1][i]);
    }
  //  printf("\n");
    for(int i = 2;i<=n/2;i++){
        LL res=0,res2=0;
       // printf("0 ");
        for(int j = 2;j<=n;j++){
            if(a[j]!=a[j-1])res2=res;
            dp[i][j]=res2;
            //(j-i-1-i-1);
            res+=dp[i-1][j]*(val[j]-(i-1)-(i-1))%mod;
            res%=mod;
         //   printf("%d ",dp[i][j]);
        }
     //   printf("\n");
    }
    LL ans=dp[n/2][n];
    for(auto it:m){
        ans=ans*f_pow(fra[it.y],mod-2)%mod;
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;00000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
p*t = a^2+b^2
q*t = ab
(p+2*q)*t=(a+b)^2
*/