/**
 *    author:  gary
 *    created: 31.07.2022 21:48:11
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
typedef pair<int,int> mp;
const int MAXN=1e3+20;
int a[1000+20],deg[MAXN];
vector<int> g[MAXN],rg[MAXN];
const int MOD=998244353;
void add(int &A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
int dp[1000+20];
void solve(){
    int n,m;
    cin>>n>>m;
    rb(i,1,n) cin>>a[i],g[i].clear(),rg[i].clear();
    rb(i,1,m){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        rg[v].push_back(u);
        deg[u]++;
    }
    vector<int> topo;
    queue<int> q;
    rb(i,1,n) if(!deg[i]) q.push(i);
    while (!q.empty())
    {
        auto now=q.front();
        topo.push_back(now);
        q.pop();
        for(auto it:rg[now]){
            deg[it]--;
            if(!deg[it]) q.push(it);
        }
    }
    int answer=0;
    rb(T,1,2*m){
        if(*max_element(a+1,a+1+n)==0) break;
        for(auto i:topo){
            if(a[i]){
                a[i]--;
                for(auto it:g[i]){
                    a[it]++;
                }
            }
        }
        answer++;
    }
    reverse(ALL(topo));
    // rb(i,1,n) cout<<a[i]<<endl;
    rb(i,1,n) dp[i]=a[i]%MOD;
    for(auto i:topo){
        for(auto it:g[i]){
            dp[it]+=dp[i];
            dp[it]%=MOD;
        }
    }
    add(answer,dp[topo.back()]);
    cout<<answer<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}