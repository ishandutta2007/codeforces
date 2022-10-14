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

vl fac, invfac;
ll choose(ll a, ll b){
  return (((fac[a]*invfac[b])%MOD)*invfac[a-b])%MOD;
}
int main(){
    fast_io();

    fac = vl(200005);
    invfac = vl(200005);
    fac[0] = 1;
    fac[1] = 1;
    invfac[0] = 1;
    invfac[1] = 1;
    for(int i=2; i<200005; i++){
      fac[i] = (fac[i-1]*i)%MOD;
      invfac[i] = minv(fac[i]);
    }

    ll f, w, h;
    cin >> f >> w >> h;
    ll tot = choose(f+w, w);

    ll good = 0;
    if(w==0) good = 1;
    h++;
    for(ll uses = 1; uses*h <= w && uses <= f+1; uses++){
      good += (choose(f+1, uses) * choose(w-uses*h + uses-1, uses-1))%MOD;
      good %= MOD;
    }
    /*
    h++;
    ll comp = 0;
    for(ll aside = 1; aside*h<=w && aside<=f+1; aside++){
      ll add = (choose(f+w-aside*h, f)*choose(f+1, aside))%MOD;
      if(aside%2==1){
        comp += add;
      }else{
        comp -= add;
        comp += MOD;
        comp %= MOD;
      }
    }
    */
    cout << (good*minv(tot)) % MOD << "\n";


}