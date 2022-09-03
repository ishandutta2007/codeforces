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
    LL n,k;
    scanf("%lld %lld",&n,&k);
    LL l[2005],r[2005],a[2005];
    for(int i = 1;i<=n;i++)scanf("%lld %lld %lld",&l[i],&r[i],&a[i]);
    LL dp[2005][2];
    dp[0][0]=dp[0][1]=0;
    for(int i = 1;i<=n;i++)dp[i][0]=dp[i][1]=1e18;
    for(int i = 1;i<=n;i++){
        LL sum=k,lastt=l[i]-1,lastm=0,b=k;
        if(l[i]!=r[i-1]){
            dp[i-1][0]=min(dp[i-1][0],dp[i-1][1]);
        }
        for(int j = i;j<=n;j++){
            LL tot=r[j]-l[j];
              sum+=tot*k;
            tot*=k;
            tot+=b;
            if(tot<a[j]){
                break;
            }     
            tot-=a[j];
            sum-=tot/k*k;
            b=tot%k;       
            if(tot/k==0){
                if(j==n)
                dp[j][1]=min(dp[j][1],dp[i-1][0]+sum-b);
                else
                dp[j][1]=min(dp[j][1],dp[i-1][0]+sum);
            }
            else{
                if(j==n)
                dp[j][1]=min(dp[j][1],dp[i-1][0]+sum-b);
                else
                dp[j][0]=min(dp[j][0],dp[i-1][0]+sum);
            }
        }
      //  printf("%lld %lld\n",dp[i][0],dp[i][1]);
    }
    if(dp[n][0]>1e15&&dp[n][1]>1e15){
        printf("-1\n");
    }
    else{
        printf("%lld\n",min(dp[n][0],dp[n][1]));
    }
}
int main(){
/*    for(int i = 0;i<=1000;i++){
        p[i]=mp(-1,-1);
    }
    for(int i = 0;i*5<=1000;i++){
        for(int j = 0;i*5+j*7<=1000;j++){
            p[i*5+j*7]=mp(i,j);
        }
    }*/
    int t=1;
  //  scanf("%d",&t);
    while(t--){
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