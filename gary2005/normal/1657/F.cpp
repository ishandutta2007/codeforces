/**
 *    author:  gary
 *    created: 22.03.2022 22:29:01
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
struct twosat{
    int n;
    vector< vector<int> > g, gt;
    vector<bool> vis, res;
    vector<int> comp;
    stack<int> ts;
    twosat(int vars = 0) {
        n = vars << 1;
        g.resize(n);
        gt.resize(n);
    }
    void add(int a,bool af,int b,bool bf) {
        a += a + (af ^ 1);
        b += b + (bf ^ 1);
        g[a].push_back(b);
        gt[b].push_back(a);
    }
    void dfs1(int u) {
        vis[u] = true;
        for(int v : g[u]) if(!vis[v]) dfs1(v);
        ts.push(u);
    }
    void dfs2(int u, int c) {
        comp[u] = c;
        for(int v : gt[u]) if(comp[v] == -1) dfs2(v, c);
    }
    bool ok() {
        vis.resize(n, false);
        rep(i,n) if(!vis[i]) dfs1(i);
        int scc = 0;
        comp.resize(n, -1);
        while(!ts.empty()) {
        int u = ts.top();
        ts.pop();
        if(comp[u] == -1) dfs2(u, scc++);
        }
        res.resize(n / 2);
        for(int i = 0; i < n; i += 2) {
        if(comp[i] == comp[i + 1]) return false;
        res[i / 2] = (comp[i] > comp[i + 1]);
        }
        return true;
    }
}solver;
const int MAXN=4e5+10;
int n,q,cnt,in[MAXN],out[MAXN],fa[MAXN];
vector<int> g[MAXN];
bool islca(int u,int v){
    return in[u]<=in[v]&&out[u]>=out[v];
}
void init(int now,int pre){
    fa[now]=pre;
    in[now]=++cnt;
    for(auto it:g[now]) if(it!=pre) init(it,now);
    out[now]=++cnt;
}
vector<int> getpath(int u,int v){// u->v
    vector<int> v1;
    while (true){
        v1.PB(u);
        if(islca(u,v)) break;
        u=fa[u];
    }
    vector<int> v2;
    while (v!=u)
    {
        v2.PB(v);
        v=fa[v];
    }
    // for(auto it:v1) cout<<it<<",";
    // cout<<endl;
    // for(auto it:v2) cout<<it<<",";
    // cout<<endl;
    reverse(ALL(v2));
    for(auto it:v2) v1.PB(it);
    return v1;
}
tuple<int,int,string> t[MAXN];
vector<char> se[MAXN];
void gg(){
    cout<<"NO\n";
    exit(0);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    solver=twosat(n);
    rb(i,1,n-1){
        int u,v;
        cin>>u>>v;
        --u;
        --v;
        g[u].PB(v);
        g[v].PB(u);
    }
    init(0,-1);
    rb(i,1,q){
        int x,y;
        string s;
        cin>>x>>y>>s;
        x--,y--;
        t[i]=make_tuple(x,y,s);
        auto p=getpath(x,y);
        // for(auto it:p) cout<<it<<" ";
        // cout<<endl;
        // cout<<p.size()<<" "<<s.length()<<endl;
        rep(j,p.size()) se[p[j]].PB(s[j]);
        reverse(ALL(p));
        rep(j,p.size()) se[p[j]].PB(s[j]);
    }
    rep(i,n){
        if(se[i].size()>2) se[i].resize(2);
        else se[i].PB('a'),se[i].PB('b');
    }
    // rep(i,n){
        // cout<<se[i][0]<<" "<<se[i][1]<<endl;
    // }
    rb(i,1,q){
        int x,y;
        string s;
        tie(x,y,s)=t[i];
        auto p=getpath(x,y);
        vector<int> c1(p.size()),c2(p.size());
        rep(j,p.size()){
            if(se[p[j]][0]==s[j]){
                c1[j]=0;
            }
            else if(se[p[j]][1]==s[j]){
                c1[j]=1;
            }
            else{
                c1[j]=-1;
            }
        }
        reverse(ALL(s));
        rep(j,p.size()){
            if(se[p[j]][0]==s[j]){
                c2[j]=0;
            }
            else if(se[p[j]][1]==s[j]){
                c2[j]=1;
            }
            else{
                c2[j]=-1;
            }
        }
        bool ban1,ban2;
        ban1=ban2=0;
        rep(j,p.size()){
            if(c1[j]==-1) ban1=1;
            if(c2[j]==-1) ban2=1;
        }
        if(ban1&&ban2){
            cout<<"NO\n";
            return 0;
        }
        if(ban1){
            rep(j,p.size()){
                solver.add(p[j],c2[j]^1,p[j],c2[j]);
            }
            continue;
        }
        if(ban2){
            rep(j,p.size()){
                solver.add(p[j],c1[j]^1,p[j],c1[j]);
            }
            continue;
        }
        vector<pair<int,mp> > diff;
        rep(j,p.size()){
            if(c1[j]==c2[j]){
                solver.add(p[j],c1[j]^1,p[j],c1[j]);
            }
            else{
                diff.PB(II(p[j],II(c1[j],c2[j])));
            }
        }
        rep(j,diff.size()) if(j){
            solver.add(diff[j].first,diff[j].second.first,diff[j-1].first,diff[j-1].second.first);
            solver.add(diff[j].first,diff[j].second.second,diff[j-1].first,diff[j-1].second.second);
        }
        reverse(ALL(diff));
        rep(j,diff.size()) if(j){
            solver.add(diff[j].first,diff[j].second.first,diff[j-1].first,diff[j-1].second.first);
            solver.add(diff[j].first,diff[j].second.second,diff[j-1].first,diff[j-1].second.second);
        }
    }
    if(solver.ok()){
        cout<<"YES\n";
        rep(i,n) cout<<se[i][solver.res[i]];
        cout<<endl;
    }
    else{
        cout<<"NO\n";
    }
    return 0;
}