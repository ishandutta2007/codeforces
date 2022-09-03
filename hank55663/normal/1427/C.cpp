#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int r,n;
    scanf("%d %d",&r,&n);
    int t[100005],x[100005],y[100005];
    t[0]=0;
    x[0]=y[0]=1;
    for(int i = 1;i<=n;i++){
        scanf("%d %d %d",&t[i],&x[i],&y[i]);
    }
    int dp[100005];
    MEM(dp);
    int ans=0;
    for(int i = 1;i<=n;i++){
        dp[i]=-1e9;
        for(int j = max(0,i-2000);j<i;j++){
            if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j]){
              //  printf("%d %d\n",i,j);
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ans=max(ans,dp[i]);
       // printf("?%d ",dp[i]);
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        //cout<<"Case "<<T++<<":\n";
        solve();
    }
}
/*


*/
/*
1 6 6
2 7 4
3 5 2
4 3 1
5 2 5
6 4 0
7 1 3
*/
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/