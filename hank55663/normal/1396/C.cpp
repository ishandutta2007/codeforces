#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL a[1000005];
LL need[1000005];
LL dp[1000005];
LL pre[1000005];
void solve(){
    LL n,r1,r2,r3,d;
    scanf("%lld %lld %lld %lld %lld",&n,&r1,&r2,&r3,&d);

    for(int i = 1;i<=n;i++)scanf("%lld",&a[i]);
    LL Min=1e18;
    for(int i = 1;i<=n;i++){
        need[i]=min(a[i]*r1+r3,a[i]*r1+r1*2+d*2);
        need[i]=min(need[i],r2+2*d+r1);
        pre[i]=min(need[i],r1+min(r2,r1*a[i]+r1))+pre[i-1];
      //  printf("%d ",need[i]);
        dp[i]=min(dp[i-1]+need[i],Min+i*d*2-d*2+pre[i]);
        Min=min(Min,dp[i-1]-(i-1)*d*2-pre[i-1]);
//        need[i]+=need[i-1];
        //printf("%lld\n",dp[i]);
    }
   // printf("\n");
    LL ans=dp[n]+d*(n-1);
    LL sum=0;
  //  printf("%lld\n",ans);
    for(int i = n-1;i>=1;i--){
      
        sum+=min(need[i],r2+r1)+d;
        ans=min(ans,dp[i-1]+sum+need[n]+d*(n-1));
    //    printf("%d %lld\n",i,need[i-1]+sum+need[n]+d*(n-1));
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/