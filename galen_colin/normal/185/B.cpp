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
 
#define f0r(a, b) for (long long a = 0; a < (b); a++)
#define f1r(a, b, c) for (long long a = (b); a < (c); a++)
#define f0rd(a, b) for (long long a = (b); a >= 0; a--)
#define f1rd(a, b, c) for (long long a = (b); a >= (c); a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define mp make_pair
#define f first
#define s second
#define presum(p, a, n) {p[0] = a[0]; for (int i = 1; i < (n); i++) p[i] = a[i] + p[i-1];}
#define all(v) v.begin(), v.end()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = lb; ele <= rb; ele++) { if (ele > lb) cout << " "; cout << a[ele]; } cout << '\n';}
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
 
// template<typename A, typename B> ll max(A x, B y) {
//   return x > y ? x : y;
// }
// template<typename A, typename B> ll min(A x, B y) {
//   return x < y ? x : y;
// }
 
mt19937 rng(steady_clock::now().time_since_epoch().count());
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}



const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;

ll n, m, k, q, Q, T, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
lld c[1000005];
string s, t;
ll ans = 0;

pll pos[3];

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");
 
  lld s;
  cin >> s;
  f0r(i, 3) {
    cin >> pos[i].f;
    pos[i].s = i;
  }
  sort(pos, pos + 3);

  cout << setprecision(13) << fixed;
  ms(c, 0);
  lld l = 1e-9, r = s;
  lld best = -1e9;
  f0r(it, 150) {
    lld mm1 = l + (r - l) / 3, mm2 = r - (r - l) / 3;

    lld lv = 1e-9, rv = s - mm1;
    f0r(it, 150) {
      lld m1 = lv + (rv - lv) / 3, m2 = rv - (rv - lv) / 3;

      lld v1 = pos[0].f * log(m1) + pos[1].f * log(s - mm1 - m1);
      lld v2 = pos[0].f * log(m2) + pos[1].f * log(s - mm1 - m2);

      if (v1 < v2) lv = m1;
      else rv = m2;
    }

    lld b1 = pos[0].f * log(lv) + pos[1].f * log(s - mm1 - lv) + pos[2].f * log(mm1);

    lv = 1e-9, rv = s - mm1;
    f0r(it, 150) {
      lld m1 = lv + (rv - lv) / 3, m2 = rv - (rv - lv) / 3;

      lld v1 = pos[0].f * log(m1) + pos[1].f * log(s - mm2 - m1);
      lld v2 = pos[0].f * log(m2) + pos[1].f * log(s - mm2 - m2);

      if (v1 < v2) lv = m1;
      else rv = m2;
    }

    lld b2 = pos[0].f * log(lv) + pos[1].f * log(s - mm2 - lv) + pos[2].f * log(mm2);

    if (b1 < b2) {
      l = mm1;
      if (b2 > best) {
        c[pos[0].s] = lv;
        c[pos[1].s] = s - mm2 - lv;
        c[pos[2].s] = mm2;
      }
    }
    else {
      r = mm2;
      if (b1 > best) {
        c[pos[0].s] = lv;
        c[pos[1].s] = s - mm1 - lv;
        c[pos[2].s] = mm1;
      }
    }
  }

  f0r(i, 3) cout << c[i] << " ";
}