/**
 *    author:  gary
 *    created: 15.10.2022 22:25:48
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
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=2e5+20;
map<int,LL> dp[MAXN];
vector<int> g[MAXN];
int s[MAXN];
LL dfs(int now,int k){
    if(k==0) return 0;
    auto ite=dp[now].find(k);
    if(ite!=dp[now].end()) return ite->second;
    LL rest=0;
    if(!g[now].empty()){
        if(k%g[now].size()==0){
            for(auto it:g[now]) rest+=dfs(it,k/g[now].size());
        }
        else{
            int A=k/g[now].size(),B=A+1,C=k%g[now].size();
            vector<LL> v;
            for(auto it:g[now]){
                auto temp=dfs(it,A);
                rest+=temp;
                v.push_back(dfs(it,A+1)-temp);
            }
            sort(ALL(v));
            reverse(ALL(v));
            rep(j,C) rest+=v[j];
        }
    }
    return dp[now][k]=rest+1ll*k*s[now];
}
void solve(){
    int n,k;
    cin>>n>>k;
    rb(i,1,n) dp[i].clear(),g[i].clear();
    rb(i,2,n){
        int p;
        cin>>p;
        g[p].push_back(i);
    }
    rb(i,1,n) cin>>s[i];
    cout<<dfs(1,k)<<endl;
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