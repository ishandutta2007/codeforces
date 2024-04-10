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
int value[5000005];
LL dp[5000005];
LL DP(int x){
    if(dp[x]!=-1)return dp[x];
    dp[x]=1e18;
    //for(LL it:factor[x]){
        LL Siz=x/value[x];
        dp[x]=min(dp[x],DP(value[x])+value[x]*Siz*(Siz-1)/2);
    //}
    return dp[x];
}
int mod=1e9+7;
int main(){
    for(int i = 1;i<=5000000;i++){
       // if(i%100==0)
       // printf("%d\n",i);
        for(int j =2*i;j<=5000000;j+=i){
            value[j]=i;
        }
    }
   // printf("?\n");
    MEMS(dp);
    dp[1]=0;
    int t,l,r;
    scanf("%d %d %d",&t,&l,&r);
    LL ans=0;
    LL temp=1;
    for(int i =l;i<=r;i++){
        ans+=temp*(DP(i)%mod)%mod;
        temp=temp*t%mod;
     //   printf("%d\n",DP(i));
    }
    printf("%lld\n",ans%mod);
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/