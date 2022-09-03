#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define MXN 500005
LL dp[65][6];
int mod=1e9+7;
void solve(){
    for(int i = 0;i<6;i++){
        dp[1][i]=1;
    }
    int k;
    scanf("%d",&k);
    for(int i = 2;i<=k;i++){
        for(int j = 0;j<6;j++){
            dp[i][j]=(((dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+dp[i-1][4]+dp[i-1][5])-dp[i-1][j]-dp[i-1][(j+3)%6])%mod+mod)%mod;
            dp[i][j]=dp[i][j]*dp[i][j]%mod;
            dp[i][j]=(dp[i][j]%mod+mod)%mod;
        }
    }
    LL res=0;
    for(int j = 0;j<6;j++)res+=dp[k][j];
    printf("%lld\n",res%mod);
}
int main(){

    int t=1;0000;
 //   scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        //cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
60.0 0.0 50.0 170.0 
3
40.0 0.0 0.0 0.0
5.0 20.0 5.0 170.0
95.0 0.0 95.0 80.0


0.0 1.0 4.0 1.0 
1
0.0 0.0 4.0 0.0
*/