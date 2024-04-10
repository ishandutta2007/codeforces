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
#define index Index
const int mod=1e9+7;
pll *dp[2005];
pll pool[2005][4005];
pll operator+(const pll &p,const pll &q){
    return mp((p.x+q.x)%mod,(p.y+q.y)%mod);
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<=n;i++){
        dp[i]=pool[i]+2002;
        MEM(pool[i]);
    }
    dp[0][0]=mp(0,1);
    char a[2005],b[2005];
    scanf("%s %s",a+1,b+1);
    for(int i = 1;i<=n;i++){
       /*  for(int j=-n;j<=n;j++){
            printf("(%d,%d) ",dp[i][j].x,dp[i][j].y);
        }
        printf("\n");*/
        for(int j = 0;j<2;j++){
            for(int k = 0;k<2;k++){
                if(a[i]-'0'==j||a[i]=='?'){
                    if(b[i]-'0'==k||b[i]=='?'){
                        if(k==j){
                            for(int a = -2000;a<=2000;a++){
                                dp[i][a]=dp[i][a]+dp[i-1][-a];
                                dp[i][a].x+=dp[i-1][-a].y*abs(-a)%mod;
                            }
                        }
                        else if(j){
                            for(int a = -2000;a<=2000;a++){
                                dp[i][-a-1]=dp[i][-a-1]+dp[i-1][a];
                                dp[i][-a-1].x+=dp[i-1][a].y*abs(-a-1)%mod;
                                dp[i][-a-1].x%=mod;
                            }
                        }
                        else if(k){
                            for(int a=-2000;a<=2000;a++){
                                dp[i][-a+1]=dp[i][-a+1]+dp[i-1][a];
                                dp[i][-a+1].x+=dp[i-1][a].y*abs(-a+1)%mod;
                                dp[i][-a+1].x%=mod;
                           /* }
                            for(int a=1;a<=2000;a++){
                                dp[i][-a+1]=dp[i][-a+1]+dp[i-1][a];*/
                            }
                        }
                      /*  for(int j=-n;j<=n;j++){
                            printf("!(%d,%d) ",dp[i][j].x,dp[i][j].y);
                        }
                        printf("\n");*/
                    }
                }
            }
        }
       /* for(int j=-n;j<=n;j++){
            printf("(%d,%d) ",dp[i][j].x,dp[i][j].y);
        }
        printf("\n");*/
    }
    printf("%lld\n",dp[n][0].x);
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/