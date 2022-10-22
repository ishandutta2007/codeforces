#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2")

#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define FILENAME sadcactus


template <typename T, bool overflow_guard = false>
struct fraction {
  T num, den;
  explicit fraction(const T& n = 0, const T& d = 1) {
    T g = gcd(n, d);
    num = d < 0 ? -n/g : n/g;
    den = d < 0 ? -d/g : d/g;
  }
  fraction(const pair<T, T>& f): num(f.first), den(f.second) {} // skip gcd
  template <typename F> fraction(const fraction<F>& o): num(o.num), den(o.den) {}
  const T& numerator() const { return num; }
  const T& denominator() const { return den; }
  T floor() const { return num < 0 ? (num - den + 1) / den : num / den; }
  friend ostream& operator << (ostream& os, const fraction& v) {
    return os << v.numerator() << '/' << v.denominator();
  }
  fraction operator - () const { return fraction(pair(-num, den)); }
  fraction operator + (const fraction& o) const { return fraction(*this) += o; } 
  fraction operator - (const fraction& o) const { return fraction(*this) -= o; }
  fraction operator * (const fraction& o) const { return fraction(*this) *= o; }
  fraction operator / (const fraction& o) const { return fraction(*this) /= o; }
  fraction& operator += (const fraction& o) {
    T g = gcd(den, o.den);
    den /= g;
    num = num * (o.den / g) + o.num * den;
    g = gcd(num, g);
    num /= g;
    den *= o.den / g;
    return *this;
  }
  fraction& operator -= (const fraction& o) {
    T g = gcd(den, o.den);
    den /= g;
    num = num * (o.den / g) - o.num * den;
    g = gcd(num, g);
    num /= g;
    den *= o.den / g;
    return *this;
  }
  fraction& operator *= (const fraction& o) {
    T gn = gcd(num, o.den);
    T gd = gcd(den, o.num);
    num = num / gn * o.num / gd;
    den = den / gd * o.den / gn;
    return *this;
  }
  fraction& operator /= (const fraction& o) {
    T gn = gcd(num, o.num);
    T gd = gcd(den, o.den);
    num = num / gn * (o.num < 0 ? -o.den : o.den) / gd;
    den = den / gd * (o.num < 0 ? -o.num : o.num) / gn;
    return *this;
  }
  bool operator < (const fraction& o) const {
    if (den == 0 && o.den == 0) return num && o.num && num < o.num;
    if (den == 0) return num < 0;
    if (o.den == 0) return 0 < o.num;
    if constexpr (overflow_guard) return fraction(*this).compare_guard(o);
    else return num * o.den < o.num * den;
  }
  bool compare_guard(fraction o) { // destroys *this
    while (den != o.den) {
      T y = floor();
      T oy = o.floor();
      if (y != oy) return y < oy;
      num -= den * y;
      o.num -= o.den * oy;
      if (num == 0 || o.num == 0) break;
      if ((den > o.den && 2*num > den) || (o.den > den && 2*o.num > o.den)) {
        num = den - num;
        o.num = o.den - o.num;
      } else {
        swap(num, den);
        swap(o.num, o.den);
      }
      swap(num, o.num);
      swap(den, o.den);
    }
    return num < o.num;
  }
  bool operator > (const fraction& o) const { return o < *this; }
  bool operator == (const fraction& o) const { return num == o.num && den == o.den; }
  bool operator <= (const fraction& o) const { return operator == (o) || operator < (o); }
  bool operator >= (const fraction& o) const { return o <= *this; }
  template <typename D> D value() const { return D(num) / D(den); }
  explicit operator float() const { return value<float>(); }
  explicit operator double() const { return value<double>(); }
  explicit operator long double() const { return value<long double>(); }
  fraction abs() const { return fraction(pair(num < 0 ? -num : num, den)); }
  template <typename D = long double> D sqrt() const { return std::sqrt(value<D>()); }
  struct as_pair {
    bool operator () (const fraction& a, const fraction& b) const {
      return a.num < b.num || (a.num == b.num && a.den < b.den);
    }
  };
};


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

constexpr char nl = '\n';
constexpr ll INF = 0x3f3f3f3f;
constexpr ll INFLL = 0x3f3f3f3f3f3f3f3f;
constexpr ll MOD = 998244353;
constexpr ld EPS = 1e-9L;
random_device _rd; mt19937 rng(_rd());

const int N = 4e5 + 1;
vector<pair<int,int>> adj[N];
unordered_set<int> skip[N];
bool vis[N];

int solve(int u, int p, vector<pair<int,int>>& ans) {
  if(vis[u]) {
    skip[u].insert(p);
    return -1;
  }
  vis[u] = true;

  int cur = -1;
  for(auto [v, e] : adj[u]) {
    if(v == p || skip[u].count(v)) continue;
    int r = solve(v, u, ans);
    if (r == -1) {
      if (cur == -1) {
        cur = e;
      } else {
        ans.emplace_back(cur, e);
        cur = -1;
      }
    } else {
      ans.emplace_back(e, r);
    }
  }
  return cur;
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(10);
#if defined(ONLINE_JUDGE) && defined(FILENAME)
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif

  int n;
  cin >> n;

  using F = fraction<ll, true>;
  const F one(1, 1);
  map<F,int,F::as_pair> remap;
  for(int i=1, rid=0; i<=n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    F x(a, b), y(c, d);
    F dx = (x + one) / y;
    F dy = x / (y + one);
    if(!remap.count(dx)) remap[dx] = rid++;
    if(!remap.count(dy)) remap[dy] = rid++;
    adj[remap[dx]].emplace_back(remap[dy], i);
    adj[remap[dy]].emplace_back(remap[dx], i);
  }

  vector<pair<int,int>> ans;
  for(int i=0; i<size(remap); i++) {
    solve(i, -1, ans);
  }

  cout << size(ans) << nl;
  for(auto [a, b] : ans) {
    cout << a << " " << b << nl;
  }

  return 0;
}