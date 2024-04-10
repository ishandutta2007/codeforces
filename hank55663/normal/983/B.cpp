#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
using namespace std;
typedef long long LL;
int dp[5005][5005];
int DP(int l,int r){
    if(dp[l][r]!=-1)
    return dp[l][r];
    return dp[l][r]=DP(l+1,r)^DP(l,r-1);
}
int opt[5005][5005];
int OPT(int l,int r){
    if(opt[l][r]!=-1)
    return opt[l][r];
    if(l==r)
    return opt[l][r]=DP(l,r);
    return opt[l][r]=max(DP(l,r),max(OPT(l,r-1),OPT(l+1,r)));
}
int main(){
    MEMS(dp);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&dp[i][i]);
    }
    MEMS(opt);
    int q;
    scanf("%d",&q);
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        printf("%d\n",OPT(l,r));
    }
}
/*
6 4 8 2
4 8 2 2
6 8 2 2
6 4 2 2
6 2 2
6 4 2
8 2 2
XXOXX....X
OO.O....X.
..........
......X...
.....X....
..........
..........
..........
..........
..........
*/