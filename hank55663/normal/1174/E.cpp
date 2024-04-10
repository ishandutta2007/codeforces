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
#define MXN 3005
#define next Next
int mod=1e9+7;
LL dp[1000005][20];
LL query(int n,vector<int> q){
    MEM(dp);
    dp[0][0]=1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<q.size()&&j<=i;j++){
            if(q[j]-i+1<=0)
            continue;
            dp[i][j]=(dp[i-1][j-1]*(q[j]-q[j-1])+dp[i-1][j]*(q[j]-i+1))%mod;
            if(dp[i][j]<0){
                printf("%lld %d %lld %d %d %d %lld\n",dp[i-1][j-1],q[j]-q[j-1],dp[i-1][j],q[j]-i+1,i,j,dp[i][j]);
                assert(dp[i][j]>0);
            }
        }
    }
    return dp[n][q.size()-1];
}
int main(){
    int n;
    scanf("%d",&n);
    int temp=1;
    int cnt=0;
    while(temp*2<=n){temp*=2,cnt++;}
    int k=temp;
    vector<int> q;
    q.pb(0);
    while(k){
        q.pb(n/k);
        k/=2;
    }
    LL ans=query(n,q);
   // for(auto it:q)
   // printf("%d ",it);
    //printf("%lld\n",ans);
    if(temp/2*3<=n){
        for(int i =0;i<cnt;i++){
            q.clear();
            q.pb(0);
            k=temp/2*3;
            int j=0;
            while(k){
                q.pb(n/k);
                if(j==i)
                k/=3;
                else
                k/=2;
                j++;
            }
            ans+=query(n,q);
          //  for(auto it:q)
           // printf("%d ",it);
           // printf("%lld\n",ans);
        }
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