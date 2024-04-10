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
    int n, k, q;
    cin >> n >> k >> q;
    vl a(n);
    forn(i, n){
      cin >> a[i];
    }

    vector<vl> dp(k+1, vl(n));
    dp[0] = vl(n, 1);
    for(int i=1; i<k+1; i++){
      forn(j, n){
        if(j > 0){
          dp[i][j] += dp[i-1][j-1];
        }if(j < n-1){
          dp[i][j] += dp[i-1][j+1];
        }
        dp[i][j] %= MOD;
      }
    }
    vl cnt(n);
    forn(i, n){
      forn(j, k+1){
        cnt[i] = (cnt[i] + dp[j][i] * dp[k-j][i]) % MOD;
      }
    }
    //((i > 0 ? dp[k-j-1][i-1] : 0) + (i < n-1 ? dp[k-j-1][i+1] : 0))
    // cout << dp;
    // cout << cnt;
    ll tot = 0;
    forn(i, n){
      tot = ((a[i]*cnt[i]) + tot)%MOD;
    }
    forn(qi, q){
      int i, x;
      cin >> i >> x;
      i--;
      tot = (((x - a[i])*cnt[i] + tot)%MOD + MOD)%MOD;
      a[i] = x;
      cout << tot << "\n";
    }

}