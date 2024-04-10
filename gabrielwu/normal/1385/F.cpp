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

int moves;
vector<vi> conn;
vi leaves;
int k;

bool recurse(int u, int par){
  vi nleaf;
  if(conn[u].size() == 1 && par>=0){
    leaves[u] = 0;
    return true;
  }
  for(int v: conn[u]){
    if(v != par){
      if(recurse(v, u)){
        leaves[u]++;
      }else{
        nleaf.pb(v);
      }
    }
  }
  conn[u] = nleaf;
  if(par >= 0){
    conn[u].pb(par);
  }

  moves += leaves[u]/k;
  leaves[u] %= k;
  if(nleaf.size()==0 && leaves[u]==0){
    return true;
  }else{
    return false;
  }

}
int main(){
    fast_io();
    int t;
    cin >> t;
    forn(ti, t){
      int n;
      cin >> n >> k;
      vector<vi> donn = vector<vi>(n);
      forn(i, n-1){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        donn[x].pb(y);
        donn[y].pb(x);
      }
      forn(start, 1){
        conn = vector<vi>(n);
        forn(i, n){
          conn[i] = donn[i];
        }
        leaves = vi(n);
        moves = 0;


        recurse(start, -1);
        int u = start;
        while(true){
          moves += leaves[u]/k;
          leaves[u] %= k;
          if((conn[u].size() == 1 && u==start || conn[u].size()==2 && u!=start)&& leaves[u]==0){
            u = conn[u][0];
            leaves[u]++;
          }else{
            break;
          }
        }
        cout << moves << "\n";
      }
    }
}