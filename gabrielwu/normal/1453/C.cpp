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
      vii v(n, vi(n));
      vi hi(10), lo(10, n), left(10, n), right(10), cnt(10);
      forn(i, n){
        forn(j, n){
          char c;
          cin >> c;
          v[i][j] = c-'0';
          //cin >> v[i][j];
          cnt[v[i][j]]++;
          hi[v[i][j]] = max(hi[v[i][j]], i);
          lo[v[i][j]] = min(lo[v[i][j]], i);
          left[v[i][j]] = min(left[v[i][j]], j);
          right[v[i][j]] = max(right[v[i][j]], j);
        }
      }
      vi best(10);
      forn(i, n){
        forn(j, n){
          int x = v[i][j];
          if(cnt[x] <= 1) continue;
          best[x] = max(best[x], max(max(hi[x]-i, i-lo[x])*max(j, n-1-j), max(right[x]-j, j-left[x])*max(i, n-1-i)));
        }
      }
      forn(i, 10){
        cout << best[i] << " ";
      }cout << "\n";
    }
}