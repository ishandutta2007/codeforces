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

const int MAX = 2e5+5;

int main(){
    fast_io();
    int t;
    cin >> t;
    forn(ti, t){
      int n;
      cin >> n;
      vpi v(n);
      vi ints;
      forn(i, n){
        int x, y;
        cin >> x >> y;
        v[i] = mp(x, y);
        ints.pb(x);ints.pb(y);
      }
      v.pb(mp(1, 200000));
      ints.pb(1);ints.pb(200000);
      n++;
      sort(v.begin(), v.end(), [](pii a, pii b){
        if(a.s != b.s){
          return a.s<b.s;
        }return a.f>b.f;
      });
      sort(ints.begin(), ints.end());
      int ind[MAX];
      vector<vpi> lefts(2*n+5);
      forn(i, ints.size()){
        ind[ints[i]] = i+1;
      }
      forn(i, n){
        v[i].f = ind[v[i].f];
        v[i].s = ind[v[i].s];
        lefts[v[i].s].pb(mp(v[i].f, i));
      }
      vi dp(2*n+5);
      vi val(n);
      int tot = 0;
      forn(i, n){
        int ans = 0;
        dp[v[i].f-1] = 0;
        for(int j=v[i].f; j<=v[i].s; j++){
          int x = dp[j-1];
          for(pii l: lefts[j]){
            if(l.f>=v[i].f) x = max(x, val[l.s] + dp[l.f-1]);
          }
          dp[j] = x;
          ans = max(ans, x);
        }
        val[i] = ans+1;
        tot = max(tot, ans);
      }
      cout << tot << "\n";
    }

}