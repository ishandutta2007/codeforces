/**
 *    author:  gary
 *    created: 03.12.2021 18:04:38
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int GRAPH_SIZE=10000+233;
int n,k,l;
bool chg[GRAPH_SIZE];
int dist[21][21];
int dis[GRAPH_SIZE];
vector<int> g[GRAPH_SIZE];
int dp[1<<20];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k>>l;
    rb(i,1,k){
        int xi;
        cin>>xi;
        chg[xi]^=1;
        chg[xi+1]^=1;
    }
    vector<int> a(101);
    rb(i,1,l) cin>>a[i];
    int cnt=0;
    rb(i,1,n+1) cnt+=chg[i];
    vector<int> has;
    rb(i,1,n+1) if(chg[i]) has.PB(i);
    rb(i,1,n){
        rb(j,1,l){
            if(i+a[j]<=n+1){
                g[i].PB(i+a[j]);
                g[i+a[j]].PB(i);
            }
        }
    }
    rep(i,cnt){
        memset(dis,63,sizeof(dis));
        dis[has[i]]=0;
        queue<int> q;
        q.push(has[i]);
        while(!q.empty()){
            auto now=q.front();
            q.pop();
            for(auto it:g[now]) if(dis[it]==INF){
                dis[it]=dis[now]+1;
                q.push(it);
            }
        }
        rep(j,cnt){
            dist[i][j]=dis[has[j]];
        }
    }
    memset(dp,63,sizeof(dp));
    dp[0]=0;
    rep(mask,1<<cnt){
        if(dp[mask]!=INF){
            rep(i,cnt) rep(j,cnt){
                if(i!=j&&((mask>>i)&1)==0&&((mask>>j)&1)==0){
                    check_min(dp[mask|(1<<i)|(1<<j)],dp[mask]+dist[i][j]);
                }
            }
        }
    }
    if(dp[(1<<cnt)-1]==INF) dp[(1<<cnt)-1]=-1;
    cout<<dp[(1<<cnt)-1]<<endl;
    return 0;
}