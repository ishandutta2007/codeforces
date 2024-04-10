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
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
vector<int> v[200005];
int in[200005],out[200005];
int degree[200005];
int dp[200005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<pii> e;
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        in[x]++;
        out[y]++;
        e.pb(mp(x,y));
    }
    for(auto it:e){
        if(in[it.x]!=1&&out[it.y]!=1){
            v[it.x].pb(it.y);
            degree[it.y]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(degree[i]==0)q.push(i);
    }
    int ans=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        dp[x]++;
        ans=max(ans,dp[x]);
        for(auto it:v[x]){
            if(--degree[it]==0){
                q.push(it);
            }
            dp[it]=max(dp[it],dp[x]);
        }
    }
    printf("%d\n",ans);
}  
int main(){
    srand(time(NULL));
    int t=1;0000;
   // scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
1101011?0 5 1
001101?00 3 1
101000110 4 0
001011010 4 0
0101?01?? 3 3
00?1000?0 1 2
223413320
  1 1 131
  40018/76270
*/