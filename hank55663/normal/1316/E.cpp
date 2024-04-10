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
LL dp[2][128];
int a[100005];
int s[100005][7];
int main(){
    MEM(dp);
    int n,p,k;
    scanf("%d %d %d",&n,&p,&k);
    vector<pii> v;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        v.pb(mp(a[i],i));
    }
    for(int i = 0;i<n;i++){
        for(int j =0;j<p;j++){
            scanf("%d",&s[i][j]);
        }
    }
    fill(dp[0],dp[0]+128,-1e18);
    fill(dp[1],dp[1]+128,-1e18);
    dp[1][0]=0;
    
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    LL ans=0;
    for(int i = 0;i<v.size();i++){
        fill(dp[i&1],dp[i&1]+128,-1e18);
        for(int j=0;j<(1<<p);j++){
            for(int k=0;k<p;k++){
                if(j&(1<<k)){
                }
                else{
                    dp[i&1][j+(1<<k)]=max(dp[i&1][j+(1<<k)],dp[(i&1)^1][j]+s[v[i].y][k]);
                }
            }
            if(__builtin_popcount(j)+k>i)
            dp[i&1][j]=max(dp[i&1][j],dp[(i&1)^1][j]+v[i].x);
            else{
                 dp[i&1][j]=max(dp[i&1][j],dp[(i&1)^1][j]);
            }
        }
        ans=max(ans,dp[i&1][(1<<p)-1]);
       // printf("%lld %lld\n",dp[i&1][0],dp[i&1][1]);
    }
    printf("%lld\n",ans);
}
/*
9 4 
1 0 1 0 1 0 0 1 1
1 2
2 4
2 3
4 5
1 6
6 7
6 8
7 9

*/