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
    //cout << "start" << endl;
    //forn(i, 1000000){
    //  ll asd = mpow(999999, 999999);
    //}
    //cout << "STOP" << endl;
    fast_io();
    //cout << (-10)%7 << endl;
    //cout << mpow(9, 999999)-9 << endl;
    int t;
    cin >> t;
    forn(ti, t){
      ll n, p;
      cin >> n >> p;
      vi k(n);
      forn(i, n){
        cin >> k[i];
      }
      sort(k.begin(), k.end());
      ll amb = 0;
      ll diff = 0;
      int prev = k[n-1];
      for(int i=n-1; i>=0; i--){
        if(prev-k[i] > 0 && amb != 0 && p>1){
          forn(x, prev-k[i]){
            if(amb < 1000000){
              amb *= p;
            }else{
              break;
            }
          }
        }
        if(amb == 0){
          diff += mpow(p, k[i]);
          diff %= MOD;
          amb++;
        }else{
          diff -= mpow(p, k[i]);
          diff %= MOD;
          amb--;
        }
        prev = k[i];
      }
      diff = ((diff%MOD)+MOD)%MOD;
      if(amb == 0){
        cout << 0 << endl;
        //cout << (MOD-diff)%MOD << endl;
      }else{
        cout << diff%MOD << endl;
      }

    }
}