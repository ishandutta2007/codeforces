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
    int r, n;
    cin >> r >> n;
    int mx = 2*(r-1);
    vector<pair<pii, int> > v(n+1);
    v[0] = mp(mp(1, 1), 0);
    forn(i, n){
      int t, x, y;
      cin >> t >> x >> y;
      v[i+1] = mp(mp(x, y), t);
      //v[i+1] = mp(mp(0, 0), i+1);
    }
    vi dp(n+1);
    int best = 0;
    int rest = -100000000;
    int j = 0;
    for(int i=1; i<=n; i++){
      while(v[i].s - v[j].s > mx){
        rest = max(rest, dp[j]);
        j++;
      }
      //cout << i << " " << rest << "d\n";
      dp[i] = rest+1;
      for(int k=j; k<i; k++){
        if(v[i].s-v[k].s >= abs(v[i].f.f-v[k].f.f) + abs(v[i].f.s-v[k].f.s)){
          dp[i] = max(dp[i], dp[k]+1);
          //cout << i << " " << k << " k\n";
        }
      }
      best = max(dp[i], best);
    }
    //cout << dp << "\n";


    cout << best << "\n";
}