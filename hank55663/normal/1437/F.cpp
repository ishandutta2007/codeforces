#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL dp[5005][5005];
LL ca[5005][5005];
LL cb[5005][5005];
LL fra[5005][5005];
int mod=998244353;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
LL inv[5005];
void solve(){
    for(int i=0;i<5005;i++){
        fra[i][i]=1;
        //if(i==0)fra[i][i]=1;
        for(int j = i+1;j<5005;j++){
            fra[j][i]=fra[j-1][i]*j%mod;
        }
    }
    inv[1]=1;
    for(int i = 2;i<5005;i++)inv[i]=f_pow(i,mod-2);
    int n;
    int a[5005];
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    reverse(a,a+n);
    a[n]=0;
    for(int i = 1;i<=n;i++){
        ca[i][i]=cb[i][i]=0;
        for(int j = i+1;j<=n;j++){
            ca[i][j]+=ca[i][j-1];
            cb[i][j]+=cb[i][j-1];
            if(a[j]*2>a[i])
                ca[i][j+1]++;
            else
                cb[i][j+1]++;
          //  printf("%d %d %d %d\n",i,j,ca[i][j],cb[i][j]);
        }
    }
    if(a[1]*2>a[0]){
        printf("0\n");
    }
    else{
        dp[0][1]=1;
        LL sum[5005];
        MEM(sum);
        sum[1]=1;
        for(int i = 2;i<=n;i++){
            for(int j=1;j<i;j++){
                if(a[i]*2<=a[j]){
                    dp[j][i]=sum[j]*fra[ca[j][i]+cb[j][i]+j][j-1]%mod*inv[j+ca[j][i]]%mod;
               //     printf("%d %d %d %d %d?\n",sum[j],fra[ca[j][i]+cb[j][i]+j][j-1],inv[j+ca[j][i]],ca[j][i]+cb[j][i]+j,j-1);
                }
                sum[i]+=dp[j][i];
                sum[i]%=mod;
              //  printf("%d %d %d\n",i,j,dp[j][i]);
            }
            dp[0][i]=1;
            for(int j=1;j<i;j++)dp[0][i]=dp[0][i]*j%mod;
            sum[i]+=dp[0][i];
            sum[i]%=mod;
         //   printf("%d %d %d\n",i,0,dp[0][i]);
        }
        printf("%lld\n",sum[n]);
    }
}
int main(){
    int t=1;
  //  scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
12
0 0
0 -13
3 -13
3 -10
10 -10
10 10
-1 10
-1 13
-4 13
-4 10
-10 10
-10 0

*/