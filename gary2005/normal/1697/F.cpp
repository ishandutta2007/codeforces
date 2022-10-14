/**
 *    author:  gary
 *    created: 12.06.2022 22:34:01
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
#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9;
struct twosat {
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
    for(int i = 0; i < n; ++i) if(!vis[i]) dfs1(i);
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
};
int n,m,k;
int gret(int x){
    return x;
}
int les(int x){
    return x+(n*k);
}
void solve(){
    cin>>n>>m>>k;
    twosat g(n*k*2);
    rep(i,n) rep(j,k) if(j) g.add(gret(i*k+j),1,gret(i*k+j-1),1),g.add(gret(i*k+j-1),0,gret(i*k+j),0),g.add(gret(i*k+j),1,les(i*k+j-1),0),g.add(gret(i*k+j),0,les(i*k+j-1),1);
    rep(i,n) rep(j,k) if(j!=k-1) g.add(les(i*k+j),1,les(i*k+j+1),1),g.add(les(i*k+j+1),0,les(i*k+j),0),g.add(les(i*k+j),1,gret(i*k+j+1),0),g.add(les(i*k+j),0,gret(i*k+j+1),1);
    rep(i,n) g.add(gret(i*k),0,gret(i*k),1),g.add(les(i*k+k-1),0,les(i*k+k-1),1);
    rb(i,1,n-1) rep(j,k) g.add(les(i*k+j),1,les(i*k-k+j),1),g.add(gret(i*k-k+j),1,gret(i*k+j),1);
    while (m--){
        int t;
        cin>>t;
        if(t==1){
            int i,x;
            cin>>i>>x;
            --x;
            --i;
            if(x!=k-1)
            g.add(gret(i*k+x+1),0,(x==0? gret(i*k+x+1):les(i*k+x-1)),1);
            else
            g.add(gret(i*k+x),1,gret(i*k+x),0);
            if(x!=0)
            g.add(les(i*k+x-1),0,(x==k-1? les(i*k+x-1):gret(i*k+x+1)),1);
            else
            g.add(les(i*k+x),1,les(i*k+x),0);
        }
        if(t==2){
            int a,b,x;
            cin>>a>>b>>x;
            x-=2;
            a--;
            b--;
            rep(j,k) rep(l,k) if(j+l>x){
                g.add(gret(a*k+j),1,gret(b*k+l),0);
                g.add(gret(b*k+j),1,gret(a*k+l),0);
            }
        }
        if(t==3){
            int a,b,x;
            cin>>a>>b>>x;
            x-=2;
            a--;
            b--;
            rep(j,k) rep(l,k) if(j+l<x){
                g.add(les(a*k+j),1,les(b*k+l),0);
                g.add(les(b*k+j),1,les(a*k+l),0);
            }
        }
    }
    if(!g.ok()){
        cout<<"-1\n";
    }
    else{
        rep(i,n){
            rep(j,k){
                if(g.res[gret(i*k+j)]&&g.res[les(i*k+j)]){
                    cout<<j+1<<' ';
                }
            }
        }
        cout<<endl;
    }
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