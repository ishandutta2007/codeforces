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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 1500
#define hash Hash
int mod=998244353;
LL dp[1000005][2];
int d[1000005];
int val[1000005];
int l[1000005];
LL DP(int x,int op){
    if(dp[x][op]!=-1)return dp[x][op];
    dp[x][op]=0;
    for(int i =l[x];val[i]+x+val[x-i-1]==val[x]&&i<x;i++){
        if((i+1)%2==op){
            dp[x][op]+=DP(i,op^1)*DP(x-i-1,0)%mod;
         //   printf("%d %d %d\n",x,i,op);
        }
    }
    dp[x][op]%=mod;
  //  printf("%d %d %lld\n",x,op,dp[x][op]);
    return dp[x][op];
}
int ans[1000005];
int main(){
    ans[1]=1;
    ans[2]=1;
    ans[4]=1;
    ans[5]=1;
    ans[9]=1;
    ans[10]=1;
    ans[20]=1;
    ans[21]=1;
    ans[41]=1;
    ans[42]=1;
    ans[84]=1;
    ans[85]=1;
    ans[169]=1;
    ans[170]=1;
    ans[340]=1;
    ans[341]=1;
    ans[681]=1;
    ans[682]=1;
    ans[1364]=1;
    ans[1365]=1;
    ans[2729]=1;
    ans[2730]=1;
    ans[5460]=1;
    ans[5461]=1;
    ans[10921]=1;
    ans[10922]=1;
    ans[21844]=1;
    ans[21845]=1;
    ans[43689]=1;
    ans[43690]=1;
    ans[87380]=1;
    ans[87381]=1;
    ans[174761]=1;
    ans[174762]=1;
    ans[349524]=1;
    ans[349525]=1;
    ans[699049]=1;
    ans[699050]=1;
   /* MEMS(dp);
    dp[1][1]=1;
    dp[1][0]=0;
    dp[0][0]=1;
    dp[0][1]=1;
    d[1]=1;
    for(int i=2;i<=1000000;i++){
        if(__builtin_popcount(i)==1){
            d[i]=d[i-1]+1;
        }
        else{
            d[i]=d[i-1];
        }
    }
    val[1]=1;
    for(int i = 2;i<=1000000;i++){
        val[i]=val[i-1]+d[i];
    }
    l[1]=0;
    for(int i =2;i<=1000000;i++){
        l[i]=l[i-1];
        while(val[l[i]]+i+val[i-l[i]-1]!=val[i])l[i]++;
       // if(i<=10)
        //printf("%d %d\n",i,l[i]);
    }*/
    int n;
    scanf("%d",&n);
    printf("%d\n",ans[n]);
    /*
    for(int i = 1;i<=n;i++)
    if(DP(i,0)+DP(i,1))
 
    printf("%d %lld\n",i,(DP(i,0)+DP(i,1))%mod);*/
}