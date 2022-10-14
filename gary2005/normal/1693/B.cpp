/**
 *    author:  gary
 *    created: 16.06.2022 22:23:56
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
const int MAXN=2e5+20;
vector<int> g[MAXN];
int n,l[MAXN],r[MAXN];
LL x[MAXN];
int ans=0;
void dfs(int now){
    for(auto it:g[now]){
        dfs(it);
        x[now]+=x[it];
    }
    check_min(x[now],(LL)(r[now]));
    if(x[now]<l[now]){
        x[now]=r[now];
        ans++;
    }
}
void solve(){
    cin>>n;
    ans=0;
    rb(i,1,n) g[i].clear();
    rb(i,2,n){
        int p;
        cin>>p;
        g[p].PB(i);
    } 
    rb(i,1,n) cin>>l[i]>>r[i],x[i]=0;
    dfs(1);
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}