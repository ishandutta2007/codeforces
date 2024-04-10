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

vi longest_pref_suff(string& s){
    /* lps[i] is length of longest PROPER prefix of s[0..i] that is also a suffix of that string.*/
    int n = s.length();

    vi lps(n);
    int len = 0;

    int i = 1;
    while (i < n){
        if (s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if (len != 0){
                len = lps[len-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int main(){
    fast_io();
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vi lps = longest_pref_suff(t);
    vi ends = {0};
    int x = lps[m-1];
    while(x > 0){
      ends.pb(x);
      x = lps[x-1];
    }
    //cout << lps << "\n";
    //cout << ends << "\n";
    vii dp(n+1, vi(m+1, -99999999));
    dp[0][0] = 0;
    for(int i=1; i<=n; i++){
      //for(int p: ends){
      //  dp[i][p] = max(dp[i][p], dp[i-1][m]+1);
      //}
      dp[i][0] = max(dp[i-1][0], dp[i][0]);
      if(s.at(i-1) == '?'){
        //dp[i][0] = max(dp[i][0], dp[i-1][m]+1);
        dp[i][1] = max(dp[i][1], dp[i][0]);
        for(int j=2; j<=m; j++){
          dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
        }
      }else{
        char c = s.at(i-1);
        //if(c == t.at(0)) dp[i][0] = max(dp[i][0], dp[i-1][m-1]+1);
        if(c==t.at(0)) dp[i][1] = dp[i][0];
        for(int j=2; j<=m; j++){
          if(c==t.at(j-1)) dp[i][j] = dp[i-1][j-1];
        }
      }
      for(int p: ends){
        dp[i][p] = max(dp[i][p], dp[i][m]+1);
      }
    }
    //cout <<dp << "\n";
    cout << dp[n][0] << "\n";
}