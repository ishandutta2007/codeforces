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
    int t;
    cin >> t;
    forn(ti, t){
      int n;
      cin >> n;
      vl v(n-1);
      vii adj(n);
      forn(i, n-1){
        int x;
        cin >> x;
        x--;
        adj[x].pb(i+1);
        adj[i+1].pb(x);
      }
      forn(i, n-1){
        cin >> v[i];
      }
      vb seen(n);
      vi par(n);
      vl dp(n);
      vi curr(1);
      ll best = 0;
      while(curr.size() > 0){
        ll pospar=-MOD, negpar=-MOD, pos=-MOD, neg=-MOD;
        vi newcurr;
        for(int u: curr){
          seen[u] = true;
          for(int oth: adj[u]){
            if(!seen[oth]){
              par[oth] = u;
              newcurr.pb(oth);
              pospar = max(pospar, v[oth-1] + dp[u]);
              negpar = max(negpar, -v[oth-1] + dp[u]);
              pos = max(pos, v[oth-1]);
              neg = max(neg, -v[oth-1]);
            }
          }
        }

        for(int u: newcurr){
          dp[u] = max(max(-v[u-1] + pospar, v[u-1] + negpar), max(-v[u-1] + dp[par[u]] + pos, v[u-1] + dp[par[u]] + neg));
          best = max(best, dp[u]);
        }
        curr = newcurr;
      }
      cout << best << "\n";

    }
}