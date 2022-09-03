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
using namespace std;
#define MXN 100005
int dp[3005][3005];
int Max[3005];
int val[3005][3005];
vector<int> ok[3005];
bool solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            dp[i][j]=0;
            val[i][j]=0;
        }
        ok[i].clear();
        Max[i]=0;
    }
    int a[3005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        ok[a[i]+i+1].pb(i);
    }
    for(int i = 1;i<=n;i++){
        for(int j = i+1;j<=n;j++){
            val[i][j+a[j]+1]++;
            val[i][j]+=val[i][j-1];
        }
    }
    int ans=0;
    for(int i = 1;i<=n;i++){
        for(auto it:ok[i]){
            for(int j=1;j<=n;j++){
                Max[j]=max(Max[j],dp[it][j]);
            }
        }
        for(int j = 1;j<i;j++){
            if(a[j]+j>=i){
            dp[j][i]=max(dp[j][i],Max[j]+val[j][i]+1);
           // printf("%d %d %d\n",j,i,dp[j][i]);
            if(i==n)ans=max(ans,dp[j][i]+1);
            }
        }
    }
    printf("%d\n",n-ans);
    //return true;
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)solve();
   /* while(t--){
        solve();
    }*/
}
/*

2 3
1 3
4 2
2 5
3 5
1 2
5 4
*/