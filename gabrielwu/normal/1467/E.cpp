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
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
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
struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       // http://xorshift.di.unimi.it/splitmix64.c
       x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
       return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
       static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
       return splitmix64(x + FIXED_RANDOM);
   }
};
unordered_map<int, int, custom_hash> cnt, seen;
int n;
vi a;
vii conn;
int ubtot;
vb ub, db;
int tot;

void dfs(int u, int par){
  seen[a[u]]++;
  int bef = seen[a[u]];
  int bef2 = bef;
  vi branch;
  for(int v: conn[u]){
    if(v != par){
      dfs(v, u);
    }
    if(seen[a[u]] > bef2){
      bef2 = seen[a[u]];
      branch.pb(v);
    }
  }
  if(seen[a[u]] > bef){
    //upward ban
    ub[u] = true;
    ubtot++;
  }
  if(branch.size() == 1){
    for(int v: conn[u]){
      if(v!= par && v != branch[0]){
        db[v] = true;
      }
    }
  }
  if(branch.size() > 1 || seen[a[u]] - bef + 1 < cnt[a[u]] ){
    //downward ban
    db[u] = true;
    // dbtot++;
  }
}

void dfs2(int u, int par, int ubseen, int dbseen){
  if(db[u]) dbseen++;
  if(dbseen == 0 && ubseen == ubtot){
    tot++;
  }
  if(ub[u]) ubseen++;
  for(int v: conn[u]){
    if(v != par){
      dfs2(v, u, ubseen, dbseen);
    }
  }
}
int main(){
    fast_io();
    cin >> n;
    a = vi(n);
    forn(i, n){
      cin >> a[i];
      cnt[a[i]]++;
    }
    conn = vii(n);
    forn(i, n-1){
      int x, y;
      cin >> x >> y;
      conn[--x].pb(--y);
      conn[y].pb(x);
    }
    ubtot =  0;
    ub = vb(n);
    db = vb(n);
    tot = 0;

    dfs(0, -1);
    dfs2(0, -1, 0, 0);
    cout << tot << "\n";
}