/**
 *    author:  gary
 *    created: 22.05.2022 23:32:09
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
const int MAXN=2e5+10;
map<mp,int> id;
struct Topo_Sort{
    int N;
    vector<int> g[MAXN];
    int d[MAXN];
    void calc(){
        memset(d,0,sizeof(d));
        rb(i,1,N) for(auto it:g[i]) d[it]++;
        queue<int> q;
        rb(i,1,N) if(!d[i]) q.push(i);
        while (!q.empty()){
            int now=q.front();
            q.pop();
            cout<<now<<" ";
            for(auto it:g[now]) {d[it]--;if(d[it]==0) q.push(it);}
        }
        cout<<endl;
    }
};
vector<int> g[MAXN];
int fa[MAXN],cnt;
int l[MAXN],r[MAXN];
int a[MAXN];
void dfs(int now,int pre){
    l[now]=++cnt;
    fa[now]=pre;
    for(auto it:g[now]) if(it!=pre) dfs(it,now);
    r[now]=++cnt;
}
bool is_anc(int u,int v){
    return l[u]<=l[v]&&r[u]>=r[v];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    Topo_Sort solver;
    solver.N=m;
    rb(i,1,n){
        cin>>a[i];
    }
    rb(i,1,m){
        int u,v;
        cin>>u>>v;
        id[II(u,v)]=id[II(v,u)]=i;
        g[u].PB(v);
        g[v].PB(u);
    }
    rb(i,1,n) if(!l[i]){
        cnt=0;
        dfs(i,0);
    }
    rb(i,1,n){
        basic_string<int> il,ir;
        int now=i;
        while (!is_anc(now,a[i])){
            il.PB(id[II(fa[now],now)]);
            now=fa[now];
        }
        now=a[i];
        while (!is_anc(now,i)){
            ir.PB(id[II(fa[now],now)]);
            now=fa[now];
        }
        reverse(ALL(ir));
        il+=ir;
        rep(j,il.size()) if(j) solver.g[il[j-1]].PB(il[j]);
    }
    solver.calc();
    return 0;
}