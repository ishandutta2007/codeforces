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


const ll inf = (ll)1e18;

struct Line {
  mutable ll m, b, p;
  bool operator<(const Line& o) const { return m < o.m; }
  bool operator<(ll x) const { return p < x; }
};

struct LineContainer {
  using MS = multiset<Line, less<void> >;
  using iterator = MS::iterator;
  MS ms;
  // (for doubles, use inf = 1/.0, div(a,b) = a/b)
  const ll inf = LLONG_MAX;
  ll div(ll a, ll b) { // floored division
    return a / b - ((a ^ b) < 0 && a % b); }
  bool isect(iterator x, iterator y) {
    if (y == ms.end()) { x->p = inf; return false; }
    if (x->m == y->m) x->p = x->b > y->b ? inf : -inf;
    else x->p = div(y->b - x->b, x->m - y->m);
    return x->p >= y->p;
  }
  void add(ll m, ll b) {
    auto z = ms.insert({m, b, 0}), y = z++, x = y;
    while (isect(y, z)) z = ms.erase(z);
    if (x != ms.begin() && isect(--x, y)) isect(x, y = ms.erase(y));
    while ((y = x) != ms.begin() && (--x)->p >= y->p)
      isect(x, ms.erase(y));
  }
  ll query(ll x) {
    assert(!ms.empty());
    auto l = *ms.lower_bound(x);
    return l.m * x + l.b;
  }
};


int main(){

    fast_io();
    int n;
    cin >> n;
    vl v(n), pref(n), arch(n), norm(n);
    forn(i, n){
      cin >> v[i];
      pref[i] = v[i] + (i>0?pref[i-1]:0);
      arch[i] = pref[i] + (i>0?arch[i-1]:0);
      norm[i] = (i+1)*v[i] + (i>0?norm[i-1]:0);
    }
    ll best = 0;
    LineContainer lc;
    forn(i, n){
      lc.add(-i, i>1?arch[i-2]:0);
      //cout << -i << " " << (i>0?arch[i-1]:0) << "\n";
      best = max(best, norm[i] + lc.query(pref[i]));
    }

    cout << best << "\n";
}