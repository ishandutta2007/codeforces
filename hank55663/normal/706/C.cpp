#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
string s[100005];
string rev[100005];
LL dp[100005][2];
int main(){ 
    int n;
    scanf("%d",&n);
    int c[100005];
    for(int i = 0;i<n;i++)
    scanf("%d",&c[i]);
    dp[0][0]=0;
    dp[0][1]=c[0];
    for(int i = 0;i<n;i++){
        char c[100005];
        scanf("%s",c);
        s[i]=string(c);
        rev[i]=s[i];
        reverse(rev[i].begin(),rev[i].end());
    }
   // printf("%lld %lld\n",dp[0][0],dp[0][1]);
    for(int i = 1;i<n;i++){
        dp[i][0]=1e18;
        if(s[i]>=s[i-1]){
            dp[i][0]=dp[i-1][0];
        }
        if(s[i]>=rev[i-1]){
            dp[i][0]=min(dp[i][0],dp[i-1][1]);
        }
        dp[i][1]=1e18;
        if(rev[i]>=s[i-1]){
            dp[i][1]=dp[i-1][0]+c[i];
        }
        if(rev[i]>=rev[i-1]){
            dp[i][1]=min(dp[i-1][1]+c[i],dp[i][1]);
        }
       // printf("%lld %lld\n",dp[i][0],dp[i][1]);
    }
    LL ans=min(dp[n-1][0],dp[n-1][1]);
    if(ans==1e18)ans=-1;
    printf("%lld\n",ans);
}
/**/