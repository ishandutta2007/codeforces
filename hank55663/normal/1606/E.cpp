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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL C[1005][1005];
LL pw[1005][1005];
LL mod=998244353;
void build(){
    for(int i = 0;i<1005;i++){
        C[i][0]=C[i][i]=1;
        for(int j = 1;j<i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    for(int i = 1;i<1005;i++){
        pw[i][0]=1;
        for(int j = 1;j<1005;j++){
            pw[i][j]=pw[i][j-1]*i%mod;
        }
    }
}
LL dp[505][505];

void solve(){
    build();
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(j<i){
                dp[i][j]=pw[j][i];
            }
            else{
                dp[i][j]=pw[i-1][i];
                for(int k = 1;k<=i;k++){
                    dp[i][j]+=dp[k][j-i+1]*C[i][k]%mod*pw[i-1][i-k]%mod;
                    //printf("%d %d %d %d %d\n",dp[k][j-i-1],C[i][k],pw[i-1][i-1],k,j-i-1);
                    dp[i][j]%=mod;
                }
            }
           // printf("%d %d %d\n",i,j,dp[i][j]);
        }
    }
    printf("%lld\n",dp[n][m]);
}
int main(){
    int t=1;//00;//00;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
*/