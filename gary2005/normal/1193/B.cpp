/**
 *    author:  gary
 *    created: 29.03.2022 10:49:32
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
const int MAXN=1e5+10;
int n,m,k;
map<int,LL> dp[MAXN];
int d[MAXN],w[MAXN];
vector<int> g[MAXN];
void dfs(int now){
    for(auto it:g[now]){
        dfs(it);
        if(dp[it].size()>dp[now].size()){
            dp[it].swap(dp[now]);
        }
        for(auto it:dp[it]) dp[now][it.first]+=it.second;
    }
    dp[now][d[now]]+=w[now];
    auto ite=dp[now].upper_bound(d[now]);
    while (ite!=dp[now].end()){
        if(ite->second>w[now]){
            ite->second-=w[now];
            break;
        }
        else{
            w[now]-=ite->second;
            ite=dp[now].erase(ite);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    rb(i,2,n){
        int p;
        cin>>p;
        g[p].PB(i);
    }
    rb(i,1,m){
        int v;
        cin>>v;
        cin>>d[v]>>w[v];
    }
    dfs(1);
    LL ans=0;
    for(auto it:dp[1]) ans+=it.second;
    cout<<ans<<endl;
    return 0;
}