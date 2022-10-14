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

vector<vi> allowed;
vector<vector<vpi>> blocked;
int n, m, k;
ll tot;

void recurse(int a, int b){
  for(auto p: blocked[a][b]){
    allowed[p.f][p.s]++;
  }
  if(allowed[a][b] == 0){
    if(a==k-1){
      tot++;
    }else{
      forn(i, a+2){
        recurse(a+1, i);
      }
    }
  }
  for(auto p: blocked[a][b]){
    allowed[p.f][p.s]--;
  }
}
int main(){
    fast_io();
    cin >> n >> m >> k;
    vector<vpi> in(n), out(n), dist(n);
    forn(i, m){
      int u, v, w;
      cin >> u >> v >> w;
      u--;
      v--;
      out[u].pb(mp(w,v));
      in[v].pb(mp(w,u));
    }

    forn(i, n){
      if(in[i].size() == 0){
        cout << 0 << endl;
        return 0;
      }
      sort(out[i].begin(), out[i].end());
      forn(j, out[i].size()){
        dist[out[i][j].s].pb(mp(out[i].size()-1, j));
      }
    }
    //cout << dist << endl;
    allowed = vector<vi>(k, vi(k, 0));
    blocked = vector<vector<vpi>>(k, vector<vpi>(k));
    tot = 0;

    forn(i, n){
      sort(dist[i].begin(), dist[i].end());
      forn(j, dist[i].size()){
        for(int l=j+1; l<dist[i].size(); l++){
          blocked[dist[i][j].f][dist[i][j].s].pb(dist[i][l]);
        }
      }
    }

    forn(i, k){
      forn(j, k){
        vpi news;
        sort(blocked[i][j].begin(), blocked[i][j].end());
        forn(p, blocked[i][j].size()){
          if(p==0 || blocked[i][j][p-1] != blocked[i][j][p]){
            news.pb(blocked[i][j][p]);
          }
        }
        blocked[i][j] = news;
      }
    }

    //cout << blocked << endl;
    recurse(0, 0);
    cout << tot << endl;


}