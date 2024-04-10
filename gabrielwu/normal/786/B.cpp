#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define readVec(v) forn(i, v.size()){cin >> v[i];}
#define printArr(arr, n) forn(i, n){if (i) cout << " "; cout << arr[i];} cout << endl;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vi> vii;

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << ""; for(int i = 0; i < v.size(); i++) {if (i) cout << " "; cout << v[i];} return cout << "";
}

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max
void fast_io(){
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
}
void file_io(string taskname){
   string fin = taskname + ".in";
   string fout = taskname + ".out";
   const char* FIN = fin.c_str();
   const char* FOUT = fout.c_str();
   freopen(FIN, "r", stdin);
   freopen(FOUT, "w", stdout);
   fast_io();
}

vb visited;
vb triggered;
vl dist;
vl weights;
vi point;
priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll,pii>> > pq;

void visit(int a, ll b);

struct need_tree {
  int n, depth;
  vector<bool> tree;

  need_tree(int s): n(s), tree(4*s,true) {}

  void query(int l, int r, ll curr) {
    query(0, 0, n-1, l, r, curr);
  }

  bool query(int i, int tl, int tr, int ql, int qr, ll curr) {

    if(!tree[i]){
      return false;
    }

    if (tl > tr || tr < ql || qr < tl) return true;

    if(tl==tr){
      visit(tl, curr);
      tree[i] = false;
      return false;
    }
    int mid = (tl + tr) / 2;
    bool a = query(2 * i + 1, tl, mid, ql, qr, curr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr, curr);
    tree[i] = a || b;
    return tree[i];
  }
};

struct trap_tree {
  int n, depth;
  vector<vi> tree;

  trap_tree(): n(0){}
  trap_tree(int s): n(s), tree(4*s) {}

  void test(int i, ll curr){
    test(0, 0, n-1, i, curr);
  }

  void test(int i, int tl, int tr, int q, ll curr) {

    if (tl > tr || tr < q || q < tl) return;
    for(int x: tree[i]){
      if(!triggered[x]){
        pq.push(mp(weights[x]+curr, mp(point[x], point[x])));
        triggered[x] = true;
      }
    }
    tree[i].clear();
    if (tl == tr) return;

    int mid = (tl + tr) / 2;
    test(2 * i + 1, tl, mid, q, curr);
    test(2 * i + 2, mid + 1, tr, q, curr);
    return;
  }

  void  lay(int l, int r, int trap) {
    lay(0, 0, n-1, l, r, trap);
  }

  void lay(int i, int tl, int tr, int ql, int qr, int trap) {

    if (ql <= tl && tr <= qr){
      tree[i].pb(trap);
      return;
    }
    if (tl > tr || tr < ql || qr < tl) return;

    int mid = (tl + tr) / 2;
    lay(2 * i + 1, tl, mid, ql, qr, trap);
    lay(2 * i + 2, mid + 1, tr, ql, qr, trap);
    return;
  }
};
trap_tree trap;
vector<vector< pair<pii, ll> > > fan;
void visit(int u, ll d){
  if(visited[u]) return;
  //cout << "visit " << u << " " << d << endl;
  dist[u] = d;
  visited[u] = true;
  for(auto p: fan[u]){
    pq.push(mp(p.s+d, mp(p.f.f, p.f.s)));
    //cout << "c " << p.s+d << endl;
  }
  trap.test(u, d);
}

int main(){
    fast_io();
    int n, s, q;
    cin >> n >> q >> s;
    s--;
    need_tree need(n);
    trap = trap_tree(n);
    fan = vector<vector<pair<pii, ll> > >(n);
    visited = vb(n);
    triggered = vb(q);
    dist = vl(n, -1);
    weights = vl(q);
    point = vi(q);
    pq = priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll,pii>> >();

    forn(i, q){
      //cout << "i " << i << endl;
      int t;
      cin >> t;
      if(t==1){
        int v, u;
        ll w;
        cin >> v >> u >> w;
        v--;u--;
        //cout << "HI"<< endl;
        fan[v].pb(mp(mp(u, u), w));
      }else if(t==2){
        int v, l, r;
        ll w;
        cin >> v >> l >> r >> w;
        v--;l--;r--;
        //cout << "HI" << v << " " << n << endl;
        fan[v].pb(mp(mp(l, r), w));
        //cout << "HIfds"<< endl;
      }else if(t==3){
        int v, l, r; ll w;
        cin >> v >> l >> r >> w;
        v--;l--;r--;
        //cout << "HI"<< endl;
        trap.lay(l, r, i);
        point[i] = v;
        weights[i] = w;
      }
    }

    visit(s, 0);

    while(!pq.empty()){
      auto p = pq.top();
      pq.pop();
      //cout << p << endl;
      //cout << dist << endl;
      need.query(p.s.f, p.s.s, p.f);

    }
    cout << dist << endl;
}