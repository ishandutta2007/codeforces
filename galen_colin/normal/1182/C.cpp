#include <bits/stdc++.h>
#include <chrono> 
 
using namespace std;
using namespace std::chrono; 
 
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#define f0r(a, b) for (long long a = 0; a < (b); ++a)
#define f1r(a, b, c) for (long long a = (b); a < (c); ++a)
#define f0rd(a, b) for (long long a = (b); a >= 0; --a)
#define f1rd(a, b, c) for (long long a = (b); a >= (c); --a)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
#define fix(prec) {cout << setprecision(prec) << fixed;}
#define mp make_pair
#define f first
#define s second
#define presum(p, a, n) {p[0] = a[0]; for (int i = 1; i < (n); i++) p[i] = a[i] + p[i-1];}
#define all(v) v.begin(), v.end()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < (n); ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = (lb); ele <= (rb); ele++) { if (ele > (lb)) cout << " "; cout << a[ele]; } cout << '\n';}
typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
  cin >> p.first;
  return cin >> p.second;
}
 
mt19937 rng(steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 
 
 
ll n, m, k, q, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;

string ss[100005];
pair<ll, char> stat[100005];
map<pair<ll, char>, set<int> > cnt;
map<ll, set<int> > vcnt;
set<pair<int, pair<ll, char> > > cs;
set<pair<int, ll> > vs;

bool ivow(char a) {
  return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}

void rem(int x) {
  set<int>& a = cnt[stat[x]];
  set<int>& b = vcnt[stat[x].f];

  cs.erase(mp(a.size(), stat[x]));
  vs.erase(mp(b.size(), stat[x].f));

  a.erase(x);
  b.erase(x);

  if (a.size()) cs.insert(mp(a.size(), stat[x]));
  if (b.size()) vs.insert(mp(b.size(), stat[x].f));
}

void rm(pii x) {
  rem(x.f); rem(x.s);
}

pii getc() {
  if (!cs.size()) return mp(-1, -1);
  auto x = *cs.rbegin();
  if (x.f >= 2) {
    return mp(*cnt[x.s].begin(), *cnt[x.s].rbegin());
  }
  return mp(-1, -1);
}

pii getv() {
  if (!vs.size()) return mp(-1, -1);
  auto x = *vs.rbegin();
  if (x.f >= 2) {
    return mp(*vcnt[x.s].begin(), *vcnt[x.s].rbegin());
  }
  return mp(-1, -1);
}

pair<pii, pii> res[25005];
vpi fi, se;

void solve(int tc) {
  cin >> n;
  f0r(i, n) {
    cin >> s; ss[i] = s;
    ll cv = 0; char t;
    f0r(i, s.length()) {
      if (ivow(s[i])) {
        ++cv; t = s[i];
      }
    }

    stat[i] = mp(cv, t);
    cnt[stat[i]].insert(i);
    vcnt[cv].insert(i);
  }

  for (auto x: cnt) cs.insert(mp(x.s.size(), x.f));
  for (auto x: vcnt) vs.insert(mp(x.s.size(), x.f));

  while (1) {
    pii x = getc();
    if (x.f != -1) {
      rm(x);
      fi.pb(x);
    } else break;
  }

  while (1) {
    pii y = getv();
    if (y.f != -1) {
      rm(y);
      se.pb(y);
    } else break;
  }

  while (1) {
    pii x, y;
    if (!fi.size()) break;
    x = fi.back();
    fi.pop_back();
    if (se.size()) {
      y = se.back();
      se.pop_back();
    } else if (fi.size()) {
      y = fi.back();
      fi.pop_back();
    } else break;

    res[ans++] = mp(mp(y.f, x.f), mp(y.s, x.s));
  }

  printf("%lld\n", ans);
  f0r(i, ans) {
    pair<pii, pii> x = res[i];
    printf("%s %s\n", ss[x.f.f].c_str(), ss[x.f.s].c_str());
    printf("%s %s\n", ss[x.s.f].c_str(), ss[x.s.s].c_str());
  }
}
 
int main() {
  send help
 
  // usaco("file");
 
  int tc;
  tc = 1;
  // cin >> tc;
  for (int t = 0; t < tc; t++) solve(t);
}