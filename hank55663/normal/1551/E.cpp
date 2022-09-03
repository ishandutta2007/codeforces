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
vector<int> v[2005];
    int dp[2005][2005];
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[2005];
    for(int i = 1;i<=n;i++)v[i].clear();
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        v[a[i]].pb(i);
    }

    for(int i=0;i<=n;i++){
        for(int j = 0;j<=n;j++){
            dp[i][j]=1e9;
        }
    }
    dp[0][0]=0;
    int ans=-1;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=i;j++){
            dp[i][j]=dp[i-1][j]+1;
            //if(dp[i][j]<=n&&j>=k)ans=max(ans,dp[i][j]);
        }
        for(int j = 0;j<i;j++){
            auto it=lower_bound(v[i].begin(),v[i].end(),dp[i-1][j]+1);
            if(it!=v[i].end()){
                dp[i][j+1]=min(dp[i][j+1],*it);
            }
        }
        for(int j = 0;j<=i;j++){
         //   printf("%d ",dp[i][j]);
            if(dp[i][j]<=n&&j>=k)ans=max(ans,i);
        }
      //  printf("\n");
    }
    if(ans==-1)printf("-1\n");
    else
    printf("%d\n",n-ans);

}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 3 3 4 4 4 5 5 5 6 6 6
3 3 7 3 25
*/