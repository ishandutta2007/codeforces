/**
 *    author:  gary
 *    created: 25.03.2022 15:07:30
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
int n;
vector<int> g[100000+10];
int dep[100000+10];
void dfs(int now,int pre){
    for(auto it:g[now]) if(it!=pre) dep[it]=dep[now]^1,dfs(it,now);
}
void solve(){
    cin>>n;
    rb(i,1,n) g[i].clear();
    rb(i,1,n-1){
        int u,v;
        cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(1,0);
    rb(i,1,n) if(dep[i]) cout<<g[i].size()<<' ';else cout<<-(int)(g[i].size())<<' ';
    cout<<endl;
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