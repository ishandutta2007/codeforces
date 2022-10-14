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

vi par;
vi subsize;
vb vis;
pii rep;
vi depth;
vii adj;

int dfs(int u, int p, int d){
  depth[u] = d;
  vis[u] = true;
  int sz = 1;
  for(int v: adj[u]){
    if(p == v) continue;
    if(vis[v]){
      if(depth[v] > depth[u]){
        rep = {u, v};
      }
    }else{
      par[v] = u;
      sz += dfs(v, u, d+1);
    }
  }
  subsize[u] = sz;
  return sz;
}
int main(){
    fast_io();
    int t;
    cin >> t;
    forn(ti, t){
      ll n;
      cin >> n;
      par = vi(n);
      subsize = vi(n);
      vis = vb(n);
      depth = vi(n);
      adj = vii(n);
      forn(i, n){
        int a, b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
      }
      dfs(0, -1, 0);

      ll single = 0;
      ll curr = 0;
      int x = rep.s;
      while(x != rep.f){
        single += (subsize[x] - curr)*(subsize[x]-curr-1)/2;
        curr = subsize[x];
        x = par[x];
      }
      single += (n - curr)*(n-curr-1)/2;

      cout << n*(n-1) - single << "\n";
    }
}