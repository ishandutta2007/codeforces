#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define readVec(v) forn(i, v.size()){cin >> v[i];}
#define printArr(arr, n) forn(i, n){if (i) cout << " "; cout << arr[i];} cout << endl;
#define pb push_back
#define mp make_pair
#define MOD 998244353
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
vl fac, invfac;

ll choose(ll a, ll b){
  if(a < b) return 0;
  return (((fac[a]*invfac[a-b])%MOD)*invfac[b])%MOD;
}
int main(){
    fast_io();
    ll MAXN = 2*150005;
    fac = vl(MAXN);
    invfac = vl(MAXN);
    fac[0] = 1;
    invfac[0] = 1;
    for(int i=1; i<MAXN; i++){
      fac[i] = (fac[i-1]*i)%MOD;
      invfac[i] = minv(fac[i])%MOD;
    }
    int n;
    cin >> n;
    vl a(2*n);
    ll tot = 0;
    forn(i, 2*n){
      cin>> a[i];
    }
    sort(a.begin(), a.end());
    forn(i, n){
      tot += MOD-a[i];
      tot %= MOD;
    }

    forn(i, n){
      tot += a[i+n];
      tot %= MOD;
    }
    cout << ((choose(2*n, n)*tot)%MOD + MOD)%MOD << "\n";
}