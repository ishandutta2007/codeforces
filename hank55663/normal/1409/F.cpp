#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
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
int dp[205][205][205];
void solve(){   
    int n,k;
    scanf("%d %d",&n,&k);
    char c[205],t[10];
    scanf("%s %s",c+1,t);
    dp[0][0][0]=0;
    for(int j = 1;j<=n;j++)
        for(int a = 0;a<=k;a++)
        dp[0][j][a]=-1e9;
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j = 0;j<=n;j++){
            for(int a = 0;a<=k;a++){
                if(c[i]==t[0]&&c[i]==t[1]){
                    if(j){
                        dp[i][j][a]=dp[i-1][j-1][a]+j-1;
                    }
                }
                else if(c[i]==t[0]){
                    if(j)
                    dp[i][j][a]=dp[i-1][j-1][a];
                }
                else if(c[i]==t[1]){
                    dp[i][j][a]=dp[i-1][j][a]+j;
                }
                else{
                    dp[i][j][a]=dp[i-1][j][a];
                }
                if(a){
                    if(t[0]==t[1]){
                        if(j)
                            dp[i][j][a]=max(dp[i][j][a],dp[i-1][j-1][a-1]+j-1);
                    }
                    else{
                        if(j)
                        dp[i][j][a]=max(dp[i][j][a],dp[i-1][j-1][a-1]);
                        dp[i][j][a]=max(dp[i][j][a],dp[i-1][j][a-1]+j);
                    }
                }
                //printf("%d %d %d %d\n",i,j,a,dp[i][j][a]);
                ans=max(ans,dp[i][j][a]);
            }
        }
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
//    scanf("%d",&t);
    while(t--){
        solve();
    }
}


/*


*/