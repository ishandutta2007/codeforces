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
    int n, m, k;
    cin >> n >> m >> k;
    vii v(n+1, vi(m));
    vector<vl> dp(n, vl(m-k+1));
    forn(i, n){
      forn(j, m){
        cin >> v[i][j];
      }
    }

    forn(i, m-k+1){
      for(int j=i; j<i+k; j++){
        dp[0][i] += v[0][j] + v[1][j];
      }
    }

    for(int i=1; i<n; i++){
      vl prem(m-k+1), postm(m-k+1);
      prem[0] = dp[i-1][0];
      postm[m-k] = dp[i-1][m-k];
      for(int j=1; j<=m-k; j++){
        prem[j] = max(prem[j-1], dp[i-1][j]);
      }
      for(int j=m-k-1; j>=0; j--){
        postm[j] = max(postm[j+1], dp[i-1][j]);
      }
      forn(j, m-k+1){
        ll curr = 0;
        for(int x=j; x<j+k; x++){
          curr += v[i][x] + v[i+1][x];
        }
        ll best = -999999999;
        if(j>=k) best = max(best, prem[j-k]);
        if(j<=m-2*k) best = max(best, postm[j+k]);
        ll sub = 0;
        for(int x=j-k+1; x<=j+k-1; x++){
          if(x<=j) sub += v[i][x+k-1];
          else if(x>j) sub -= v[i][x-1];
          //cout << i << " " << j << " " << x << " " << sub << endl;
          if(x>=0 && x<=m-k) best = max(best, dp[i-1][x]-sub);
        }
        dp[i][j] = curr + best;
      }

    }
    //cout << dp << endl;
    ll ans = 0;
    forn(i, m-k+1){
      ans = max(ans, dp[n-1][i]);
    }
    cout << ans << "\n";

}