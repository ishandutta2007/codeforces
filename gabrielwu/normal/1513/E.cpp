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

ll minv(ll base) {
    return mpow(base, MOD - 2);
}

int main(){
    fast_io();
    int n;
    cin >> n;
    vl fac(2*n+5), ifac(2*n+5);
    fac[0] = 1;
    ifac[0] = 1;
    forn(i, 2*n){
      fac[i+1] = (fac[i] * (i+1))%MOD;
      ifac[i+1] = minv(fac[i+1]);
    }
    function<ll(int, int)> choose = [&](int a, int b){
      return (((fac[a]*ifac[b])%MOD)*ifac[a-b])%MOD;
    };

    vl v(n);
    ll s = 0;
    forn(i, n){
      cin >> v[i];
      s += v[i];
    }
    if(s%n != 0){
      cout << 0 << "\n";
      return 0;
    }
    ll av = s/n;
    vl pos, neg;
    int zer = 0;
    forn(i, n){
      v[i] -= av;
      if(v[i] < 0){
        neg.pb(v[i]);
      }else if(v[i] > 0){
        pos.pb(v[i]);
      }else{
        zer++;
      }
    }
    if(zer == n){
      cout << "1\n";
      return 0;
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    ll pperm = fac[pos.size()];
    ll bef = MOD;
    int run = 0;
    forn(i, pos.size()){
      if(pos[i] == bef) run++;
      else{
        pperm = (pperm * ifac[run])%MOD;
        run = 1;
        bef = pos[i];
      }
    }
    pperm = (pperm * ifac[run])%MOD;
    ll nperm = fac[neg.size()];
    bef = MOD;
    run = 0;
    forn(i, neg.size()){
      if(neg[i] == bef) run++;
      else{
        nperm = (nperm * ifac[run])%MOD;
        run = 1;
        bef = neg[i];
      }
    }
    nperm = (nperm * ifac[run])%MOD;

    ll tot = choose(n, zer);
    n -= zer;
    if(pos.size() == 1){
      tot = (tot*n)%MOD;
      tot = (tot*nperm)%MOD;
    }else if(neg.size() == 1){
      tot = (tot*n)%MOD;
      tot = (tot*pperm)%MOD;
    }else{
      tot = (tot*2)%MOD;
      tot = (tot*pperm)%MOD;
      tot = (tot*nperm)%MOD;
    }
    cout << tot << "\n";
}