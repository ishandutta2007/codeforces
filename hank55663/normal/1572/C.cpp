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
const int mod=998244353;
int a[3005];
vector<int> v[3005];
int dp[3005][3005];
int DP(int l,int r){
    if(dp[l][r]!=-1)return dp[l][r];
    if(l>=r)return 0;
    dp[l][r]=0;
    dp[l][r]=DP(l+1,r);
    for(auto it:v[a[l]]){
        if(it>l&&it<=r){
            assert(a[it]==a[l]);
            dp[l][r]=max(dp[l][r],DP(l+1,it-1)+DP(it,r)+1);
        }
    }
    return dp[l][r];
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=3000;i++){
        v[i].clear();
        for(int j = i;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        v[a[i]].pb(i);
    }
    printf("%d\n",n-1-DP(1,n));
}
int main(){
    int t=1;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
000010000
001010000
001010100
001011100

1 1 2
1 1 2 1
2 1
2


XOXOXOXOOXOXXOXOXOXOOXOX
*/