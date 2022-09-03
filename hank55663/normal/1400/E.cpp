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
LL dp[5005][5005];
int a[5005];
LL DP(int l,int r){
    if(l>r)return 0;
    int Min=1e9;
    int ans=0;
    for(int i = l;i<=r;i++){
        Min=min(Min,a[i]);
        if(a[i])ans++;
    }
    int less=l-1;
    int ans2=Min;
    for(int i = l;i<=r;i++){
        a[i]-=Min;
        if(!a[i]){
            ans2+=DP(less+1,i-1);
            less=i;
        }
        //if(dp[l][r])
    }
    ans2+=DP(less+1,r);
 //   printf("%d %d %d %d\n",l,r,ans,ans2);
    return min(ans,ans2);
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    printf("%lld\n",DP(1,n));
}
int main(){
    int t=1;
    //scanf("%d",&t);
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