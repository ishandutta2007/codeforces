
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
int dp[200005][2][2];
void solve(int T){
    int n;
    scanf("%d",&n);
    char c[2][200005];
    scanf("%s %s",c[0],c[1]);
    if(c[0][0]=='1')dp[0][0][0]=1;
    else dp[0][0][0]=0;
    if(c[1][0]=='1')dp[0][1][1]=dp[0][0][0]+1;
    else dp[0][1][1]=-100;
    dp[0][0][1]=-100;
    dp[0][1][0]=-100;
    int ans=0;
       for(int a=0;a<2;a++)for(int b=0;b<2;b++)ans=max(ans,dp[0][a][b]);
    //    printf("\n");
    for(int i = 1;i<=n;i++){
        int add1=0,add2=0;
         if(c[0][i]=='1'){
             add1=1;
        } if(c[1][i]=='1'){
            add2=1;
        }
        dp[i][0][0]=max(dp[i-1][0][0],dp[i-1][1][0])+add1;
        dp[i][0][1]=max(dp[i-1][1][1],dp[i-1][0][1])+add2;
        if(add1)
        dp[i][1][0]=dp[i-1][0][1]+add1+add2;
        else
        dp[i][1][0]=-100;
        if(add2)
        dp[i][1][1]=dp[i-1][0][0]+add1+add2;
        else
         dp[i][1][1]=-100;
        for(int a=0;a<2;a++)for(int b=0;b<2;b++)/*printf("%d ",dp[i][a][b]),*/ans=max(ans,dp[i][a][b]);
      //  printf("\n");
    }
    printf("%d\n",ans);
    
    
}
int main(){
    int t=1;
 //   scanf("%d",&t);
    for(int T=1;T<=t;T++){
       // cerr<<T<<endl;
        solve(T);
    }
   // printf("%d\n",s.size());
}

/*
*/