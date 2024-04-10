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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 205
double a[18][18];
double dp[1<<18][18];
double DP(int x,int p,int n){
    if(dp[x][p]>=0)
    return dp[x][p];
    dp[x][p]=0;
    for(int i = 0;i<n;i++){
        if(x&(1<<i)){
            dp[x][p]=max(dp[x][p],DP(x-(1<<i),p,n)*a[p][i]+DP(x-(1<<i),i,n)*a[i][p]);
        }
    }
    return dp[x][p];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%lf",&a[i][j]);
        }
    }
    MEMS(dp);
    dp[0][0]=1;
    double ans=0;
    for(int i = 0 ; i < n ; i++){
        ans=max(ans,DP((1<<n)-1-(1<<i),i,n));
    }
    printf("%lf\n",ans);
}
/*

*/