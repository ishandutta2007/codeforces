#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define MXN 10005
#define N (1<<20)
int main(){
    int n;
    scanf("%d",&n);
    int a[2][100005];
    for(int i = 0;i<2;i++){
        for(int j =1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    LL dp[100005][2];
    MEM(dp);
    dp[1][0]=a[0][1];
    dp[1][1]=a[1][1];
    LL ans=max(dp[1][0],dp[1][1]);
    for(int j=2;j<=n;j++){
        for(int i = 0;i<2;i++){
            dp[j][i]=max(dp[j-1][i^1],max(dp[j-2][i],dp[j-2][i^1]))+a[i][j];
            ans=max(ans,dp[j][i]);
        }
    }
    printf("%lld\n",ans);
}
/*
1 
2 6 
3 5 
4
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

if(c[n-(r-l+1)]==)
dp[l][r]
dp[]
1 3 4 2
*/