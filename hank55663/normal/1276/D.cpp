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
LL dp[200005][4];//0 no 1 before 2 after 3 parent
vector<int> v[200005];
int mod=998244353;
void dfs(int x,int f){
    dp[x][0]=1;
    int visf=0;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            if(visf){
                dp[x][1]*=(dp[it][0]+dp[it][2]+dp[it][1]);
                dp[x][1]%=mod;
                dp[x][2]=(dp[x][2]*(dp[it][0]+dp[it][1]+dp[it][2])
                        +dp[x][0]*(dp[it][2]+dp[it][0]))%mod;
                dp[x][3]*=(dp[it][0]+dp[it][1]+dp[it][2]);
                dp[x][3]%=mod;
            }
            else{
                dp[x][1]=(dp[x][1]*(dp[it][0]+dp[it][1]+dp[it][2])
                        +dp[x][0]*(dp[it][2]+dp[it][0]))%mod;
            }
            dp[x][0]*=(dp[it][1]+dp[it][3]);
            dp[x][0]%=mod;
        }
        else{
            visf=1;
            dp[x][3]=dp[x][0];
        }
    }
  //  printf("%d %lld %lld %lld %lld\n",x,dp[x][0],dp[x][1],dp[x][2],dp[x][3]);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    printf("%lld\n",(dp[1][0]+dp[1][1]+dp[1][2]+dp[1][3])%mod);
}
/*
 (2, 6, 5, 4)
 (2, 6, 5, 7) 
 (2, 6, 7, 3) 
 (2, 6, 7, 5) 
 (2, 7, 3) 
 (2, 7, 5) 
 (7, 1, 3) 
 (7, 1, 5) 
 (7, 2, 3) 
 (7, 2, 5)
*/