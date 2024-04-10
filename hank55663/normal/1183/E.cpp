#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MXN 10005
#define less Less
int main(){
    LL n,K;
    scanf("%lld %lld",&n,&K);

    char c[105];
    scanf("%s",c+1);
    LL dp[105][105];
    MEM(dp);
    dp[0][0]=1;
    int last[26];
    MEM(last);
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<i;j++){
            dp[i][j]+=dp[i-1][j];
            dp[i][j+1]+=dp[i-1][j];
        }
        if(last[c[i]-'a']!=0)
        for(int j = 1;j<=i;j++){
            if(dp[last[c[i]-'a']-1][j-1]<1e15)
            dp[i][j]-=dp[last[c[i]-'a']-1][j-1];
        }
        last[c[i]-'a']=i;
        for(int j = 0;j<=i;j++){
            if(dp[i][j]>1e18)dp[i][j]=1e18;
           // printf("%d ",dp[i][j]);
        }
       // printf("\n");
    }
    LL sum=0,cost=0;
    for(int i = n;i>=0;i--){
        LL add=min(K-sum,dp[n][i]);
        //printf("%d %lld\n",i,dp[n][i]);
        sum+=add;
        cost+=add*(n-i);
    }
    if(sum<K)printf("-1\n");
    else printf("%lld\n",cost);
}  
/*
1 
2 6 
3 5 
4
*/