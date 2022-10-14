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

vii adj;
int diam;
int dfs(int v, int par){
  vi depths;
  for(int u: adj[v]){
    if(u != par){
      depths.pb(dfs(u, v));
    }
  }
  if(depths.size() == 0){
    return 0;
  }
  sort(depths.begin(), depths.end());
  if(depths.size() >= 2){
    diam = max(diam, depths[depths.size()-1] + depths[depths.size()-2] + 2);
  }
  diam = max(diam, depths[depths.size()-1]+1);
  return depths[depths.size()-1]+1;
}
int main(){
    fast_io();
    int t;
    cin >> t;
    forn(ti, t){
      int n, a, b, da, db;
      cin >> n >> a >> b >> da >> db;
      a--;b--;
      adj = vii(n);
      forn(i, n-1){
        int x, y;
        cin >> x >> y;
        x--;y--;
        adj[x].pb(y);
        adj[y].pb(x);
      }
      if(db <= 2*da){
        cout << "Alice\n";
        continue;
      }
      diam = 0;
      dfs(0, -1);
      //cout << "diam " << diam << "\n";
      if(diam <= 2*da){
        cout << "Alice\n";
        continue;
      }
      //cout << "HI" << endl;
      vb visited(n);
      vi visit;
      visit.pb(a);
      int time = 0;
      int dist;
      while(!visited[b]){

        vi visitnext;
        for(int x: visit){
          visited[x] = true;
          if(x==b){
            dist = time;
          }
          for(int y: adj[x]){
            if(!visited[y]){
              visitnext.pb(y);
            }
          }
        }
        time++;
        visit = visitnext;
      }
      //cout << "dist" << dist <<"\n";
      if(dist <= da){
        cout << "Alice\n";
      }else{
        cout << "Bob\n";
      }
    }
}