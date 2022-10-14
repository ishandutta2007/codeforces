/**
 *    author:  gary
 *    created: 21.07.2022 23:05:50
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
int n;
int a[MAXN];
vector<int> g[MAXN];
int ans=0;
set<int> v[MAXN];
int tag[MAXN];
void dfs(int now,int pre){
    v[now].insert(a[now]);
    bool bad=0;
    for(auto it:g[now]) if(it!=pre){
        dfs(it,now);
        if(v[it].size()>v[now].size()){
            for(auto ele:v[now])
                bad|=v[it].find(ele^tag[now]^tag[it])!=v[it].end();
            tag[it]^=a[now];
            for(auto ele:v[now])
                v[it].insert(ele^tag[now]^tag[it]);
            v[now].swap(v[it]);
            swap(tag[now],tag[it]);
        }
        else{
            for(auto ele:v[it])
                bad|=v[now].find(ele^tag[now]^tag[it])!=v[now].end();
            tag[it]^=a[now];
            for(auto ele:v[it])
                v[now].insert(ele^tag[now]^tag[it]);
        }
    }
    if(bad) ans++,v[now].clear();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rb(i,1,n) cin>>a[i];
    rb(i,1,n-1){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}