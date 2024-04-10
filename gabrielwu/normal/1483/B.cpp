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

ll gcd(ll x, ll y) {
  if (y == 0) return x;
  return gcd(y, x%y);
}

int main(){
    fast_io();
    int t;
    cin >> t;
    forn(ti, t){
      int n;
      cin >> n;
      vl a(n);
      forn(i, n){cin >> a[i];}
      vb alive(n, true);
      vi right(n), left(n);
      forn(i, n){
        right[i] = i+1;
        left[i] = i-1;
      }
      right[n-1] = 0;
      left[0] = n-1;
      vi ans, check;
      forn(i, n){
        if(gcd(a[i], a[right[i]]) == 1){
          check.pb(i);
        }
      }
      while(check.size() > 0){
        vi newcheck;
        for(int x: check){
          if(alive[x]){
            ans.pb(right[x]+1);
            alive[right[x]] = false;
            left[right[right[x]]] = x;
            right[x] = right[right[x]];

            if(gcd(a[x], a[right[x]]) == 1){
              newcheck.pb(x);
            }
          }
        }
        check = newcheck;
      }

      cout << ans.size() << " ";
      forn(i, ans.size()){
        cout << ans[i] << " ";
      }cout << "\n";
    }
}