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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 100005
int dp[405][405][405];
void solve(){
    char s[405];
    char t[405];
    scanf("%s %s",s+1,t+1);
    int n=strlen(s+1),m=strlen(t+1);
    if(m>n){
        printf("NO\n");
    }
    else{
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=m;j++){
                for(int k=0;k<=m;k++){
                    dp[i][j][k]=1e9;
                }
            }
        }
        for(int j = 0 ;j<=m;j++){
            dp[0][0][j]=j;
        }
        for(int i = 0;i<=n;i++){
            for(int j =0;j<=m;j++){
                for(int k=0;k<=m;k++){
                    if(dp[i][j][k]!=1e9){
                        //printf("%d %d %d %d\n",i,j,k,dp[i][j][k]);
                        //printf("%c %c %c\n",s[i+1],t[j+1],t[k+1]);
                    }
                    if(s[i+1]==t[j+1])dp[i+1][j+1][k]=min(dp[i+1][j+1][k],dp[i][j][k]);
                    if(s[i+1]==t[k+1])dp[i+1][j][k+1]=min(dp[i+1][j][k+1],dp[i][j][k]);
                    dp[i+1][j][k]=min(dp[i+1][j][k],dp[i][j][k]);
                }
            }
        }
        for(int j = 0;j<=m;j++){
            if(dp[n][j][m]<=j){
                printf("YES\n");
                return ;
            }
        }
        printf("NO\n");
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
        
    }
}