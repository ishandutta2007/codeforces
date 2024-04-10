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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 15000
int dp[105][105][105];
int DP(int a,int b,int c){
    if(dp[a][b][c]!=-1)return dp[a][b][c];
    dp[a][b][c]=0;
    if(a>=1&&b>=2){
        dp[a][b][c]=max(dp[a][b][c],DP(a-1,b-2,c)+3);
    }
    if(b>=1&c>=2){
        dp[a][b][c]=max(dp[a][b][c],DP(a,b-1,c-2)+3);
    }
    return dp[a][b][c];
}
int main(){
    MEMS(dp);
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        printf("%d\n",DP(a,b,c));
    }
}