#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
vector<int> v;
int dp[5005][5005];
int DP(int l,int r){
    if(dp[l][r]!=-1)return dp[l][r];
    if(l>=r)return 0;
    dp[l][r]=1e9;
    if(v[l]==v[r])dp[l][r]=min(dp[l][r],DP(l+1,r-1)+1);
    dp[l][r]=min(dp[l][r],DP(l+1,r)+1);
    dp[l][r]=min(dp[l][r],DP(l,r-1)+1);
    return dp[l][r];
}
int main(){
    int n;
    MEMS(dp);
    scanf("%d",&n);
    int last=-1;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x==last)continue;
        last=x;
        v.pb(x);
    }
    printf("%d\n",DP(0,v.size()-1));
    return 0;
}