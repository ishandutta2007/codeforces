#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0; i<(n); i++)
#define readVec(v) forn(i, v.size()){cin >> v[i];}
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

ll mmul(ll x, ll y) {
    return (x * y) % MOD;
}

ll madd(ll x, ll y) {
    return (x + y) % MOD;
}

ll mdiv(ll x, ll y){
    return mmul(x, minv(y));
}

int main(){
    fast_io();
    int n;
    cin >> n;
    vi cnts(1000005, 0);
    vector<vi> choices(n);
    forn(i,n){
        int k;
        cin >> k;
        choices[i] = vi(k);
        forn(j,k){
            int x;
            cin >> x;
            cnts[x]++;
            choices[i][j] = x;
        }
    }
    ll tot = 0;
    forn(i,n){
        ll thischild = 0;
        for(int x: choices[i]){
            thischild = madd(thischild, cnts[x]);
        }
        thischild = mdiv(thischild, choices[i].size());
        tot = madd(tot, thischild);
    }
    tot = mdiv(tot, n);
    tot = mdiv(tot, n);

    cout << tot << endl;
}