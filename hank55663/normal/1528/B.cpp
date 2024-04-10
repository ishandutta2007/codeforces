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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
LL dp[1000005];
LL cnt[1000005];
const int mod=998244353;
void solve(){
   for(int i = 1;i<=1000000;i++){
       for(int j = i;j<=1000000;j+=i){
           cnt[j]++;
       }
   }
   LL sum=0;
   int n;
   scanf("%d",&n);
   for(int i = 1;i<=n;i++){
       dp[i]=(sum+cnt[i])%mod;
       sum=(sum+dp[i])%mod;
   }
   printf("%lld\n",dp[n]);
}
int main(){
    int t=1;//000;
    //scanf("%d",&t);
    while(t--)
        solve();
    /*int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }*/
}
/*
1 3 2 1
1 3 2 1
2 4 2 1
2 4 2 1
4 5 2 1
4 5 2 1
*/