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
int dp[1<<18];
int from[1<<18];

int sum[1<<18];
vector<int> v[20];
int DP(int x,int n){
    if(dp[x]!=-1)return dp[x];
    if(x==0)return 0;
    int val1=0;
    int val2=0;
    int cnt[20];
    fill(cnt,cnt+20,0);
    for(int i = 0;i<n;i++){
        if(x&(1<<i)){
            for(auto it:v[i]){
                cnt[it]++;
            }
        }
    }
    for(int i = 0;i<n;i++){
        if(cnt[i]==0&&x&(1<<i)){
            if(v[i].size())
            val1+=(1<<i);
            else
            val2+=(1<<i);
        }
    }
    dp[x]=1e9;
    for(int j=val1;j;j=(j-1)&val1){
        int res=DP(x-j-val2,n)+sum[x-j-val2];
        if(res<dp[x]){
            dp[x]=res;
            from[x]=x-j-val2;
        }
    }
    
   // printf("%d %d\n",x,dp[x]);
    if(val2==x)return dp[x]=0;
    return dp[x];
}
void solve(){
    MEMS(dp);
    int n,m;
    scanf("%d %d",&n,&m);
    pair<pii,int> p[100005];
    for(int i = 0;i<m;i++){
        int x,y,w;
        
        scanf("%d %d %d",&x,&y,&w);
        
        x--;
        y--;
        v[y].pb(x);
        p[i]=mp(mp(x,y),w);
    }
    for(int i = 1;i<(1<<n);i++){
        for(int j = 0;j<m;j++){
            if((i&(1<<p[j].x.x))&&(i&(1<<p[j].x.y))==0){
                sum[i]+=p[j].y;
            }
        }
       // printf("%d %d\n",i,sum[i]);
    }
    DP((1<<n)-1,n);
    int now=(1<<n)-1;
    int ans[20];
    int aa=0;
    while(now){
        int x=from[now];
        int y=now-x;
        for(int j = 0;j<n;j++){
            if(y&(1<<j)){
                ans[j]=aa;
            }
        }
        now=from[now];
        aa++;
    }
    for(int i = 0;i<n;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
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