#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=1e9+7;
#define MXN 2005
vector<int> v[200005];
vector<int> v2[400005];
int dis[200005];
int dp[400005];
int degree[400005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=  1;i<=n;i++)v[i].clear(),v2[i].clear(),v2[i+n].clear();
    int s,t;
    scanf("%d %d",&s,&t);
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    queue<int> q;
    q.push(s);
    fill(dis,dis+n+1,1e9+7);
    dis[s]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto it:v[x]){
            if(dis[it]>dis[x]+1){
                dis[it]=dis[x]+1;
                q.push(it);
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(auto it:v[i]){
            if(dis[it]==dis[i]+1){
                v2[i].pb(it);
                degree[it]++;
                v2[i+n].pb(it+n);
                degree[it+n]++;
            }
            else if(dis[it]==dis[i]){
                v2[i].pb(it+n);
                degree[it+n]++;
            }
        }
        dp[i]=dp[i+n]=0;
    }
    dp[s]=1;
    //queue<int> q;
    for(int i = 1;i<=2*n;i++){
        if(degree[i]==0)q.push(i);
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto it:v2[x]){
            dp[it]+=dp[x];
            dp[it]%=mod;
            if(--degree[it]==0)q.push(it);
        }
    }
    printf("%d\n",(dp[t]+dp[t+n])%mod);
}
int main(){
    int t=1;0000;
      scanf("%d",&t);
   //  while(solve());
     
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
342475
784728
394591
622354
489948
37187.5
586271
70934.1
463806
235009
528719
786392
717050
936731
250005
382783
953168
610086
*/