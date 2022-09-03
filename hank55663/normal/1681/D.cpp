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
#define MXN 10000
map<LL,int> dp;
LL n;
LL val=1;
int DP(LL x){
    if(x>=val){
        return 0;
    }
    if(dp.find(x)!=dp.end())return dp[x];
    dp[x]=1e9;
    LL tmp=x;
    while(tmp){
        if(tmp%10){
            dp[x]=min(dp[x],DP(x*(tmp%10))+1);
        }
        tmp/=10;
    }
    return dp[x];
}
void solve(){
    LL x;
    scanf("%lld %lld",&n,&x);
    val=1;
    for(int j = 1;j<n;j++)val=val*10;
    int res=DP(x);
    if(res==1e9)res=-1;
    printf("%d\n",res);
}
int main(){
   // srand(time(NULL));
    int t=1;;0000;
    //scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}