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
      string s;
      cin >> s;
      int n = s.size();
      vector<vi> dp(n+1, vi(4));
      for(int i=1; i<=n; i++){
        if(i > 1 && s.at(i-1) == s.at(i-2)){
          if(i > 2 && s.at(i-1) == s.at(i-3)){
            dp[i][0] = MOD;
            dp[i][1] = dp[i-1][3];
            dp[i][2] = min(dp[i-1][1], dp[i-1][0])+1;
            dp[i][3] = min(dp[i-1][2], dp[i-1][3])+1;
          }else{
            dp[i][0] = MOD;
            dp[i][1] = min(dp[i-1][2], dp[i-1][3]);
            dp[i][2] = min(dp[i-1][1], dp[i-1][0])+1;
            dp[i][3] = min(dp[i-1][2], dp[i-1][3])+1;
          }
        }else{
          if(i > 2 && s.at(i-1) == s.at(i-3)){
            dp[i][0] = dp[i-1][1];
            dp[i][1] = dp[i-1][3];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1])+1;
            dp[i][3] = min(dp[i-1][2], dp[i-1][3])+1;
          }else{
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = min(dp[i-1][2], dp[i-1][3]);
            dp[i][2] = min(dp[i-1][1], dp[i-1][0])+1;
            dp[i][3] = min(dp[i-1][2], dp[i-1][3])+1;
          }
        }
      }
      cout << min(min(dp[n][0], dp[n][1]), min(dp[n][2], dp[n][3])) << "\n";
    }
}