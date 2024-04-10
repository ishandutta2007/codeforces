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


int main(){
    fast_io();

    int n, m;
    cin >> n >> m;
    vector<vl> fw(n,vl(n,INT_MAX));
    vector<vpl> edges(n);
    forn(i, m){
      int u, v, w;
      cin >> u >> v >> w;
      u--;v--;
      fw[u][v] = w;
      fw[v][u] = w;
      edges[u].pb(mp(v, w));
    }
    forn(i, n){
      fw[i][i] = 0;
    }

    int q;
    cin >> q;
    vector<pair<pii, ll> > trips;
    forn(i, q){
      int u, v, l;
      cin >> u >> v >> l;
      u--;v--;
      trips.pb(mp(mp(u, v), l));
      trips.pb(mp(mp(v, u), l));
    }
    forn(k,n){
        forn(i,n){
            forn(j,n){
                if(fw[i][k] != INT_MAX && fw[k][j] != INT_MAX && fw[i][k] + fw[k][j] < fw[i][j]){
                    fw[i][j] = fw[i][k] + fw[k][j];
                }
            }
        }
    }
    int ans = 0;
    forn(a, n){
      vl need(n, -1);
      for(auto trip: trips){
        int u = trip.f.f;
        int v = trip.f.s;
        ll l = trip.s;
        need[v] = max(need[v], l-fw[u][a]);
      }
      for(pii p: edges[a]){
        int b = p.f; ll w = p.s;
        forn(v, n){
          if(w + fw[b][v] <= need[v]){
            ans++;
            break;
          }
        }
      }
    }
    cout << ans << "\n";


}