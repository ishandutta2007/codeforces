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
ll mpow(ll base, ll exp) {
  ll res = 1;
  while (exp) {
    if (exp % 2 == 1){
        res = (res * base) % MOD;
    }
    exp >>= 1;
    base = (base * base) % MOD;
  }
  return res;
}

int main(){
    fast_io();
    int t;
    cin >> t;
    vector<vl> len(2e5+5, vl(10));
    forn(i, 10){
      // v[0][i] = i;
      len[0][i] = 1;
    }
    for(int i=1; i<=2e5; i++){
      for(int j=0; j<9; j++){
        len[i][j] = len[i-1][j+1];
      }
      len[i][9] = (len[i-1][1] + len[i-1][0])%(MOD);
    }
    forn(ti, t){
      int n, m;
      cin >> n >> m;
      // vector<vl> v(m+5, vl(10));


      // for(int i=1; i<=m; i++){
      //   for(int j=0; j<9; j++){
      //     v[i][j] = v[i-1][j+1];
      //   }
      //   v[i][9] = ((mpow(10, len[i-1][0])*v[i-1][1])%MOD + v[i-1][0])%MOD;
      // }
      // cout << "len " << len << "\n";
      // cout << "v " << v << "\n";
      // ll tot = 0;
      ll acclen = 0;
      while(n > 0){
        int d = n%10;
        n/=10;
        // tot = (tot + v[m][d]*mpow(10, acclen))%MOD;
        acclen = (acclen + len[m][d])%(MOD);
      }

      cout << acclen << "\n";
    }
}