#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  map<int, int> freq;
  REP(i, n) ++freq[a[i]];
  for (const auto [_, f] : freq) {
    if (f & 1) {
      cout << "-1\n";
      return;
    }
  }
  vector<int> p, c, t;
  int m = 1, frnt = 1;
  vector<int> rem;
  map<int, int> pos;
  REP(i, n) {
    if (!pos.count(a[i])) {
      rem.emplace_back(a[i]);
      pos[a[i]] = m++;
      continue;
    }
    for (int j = pos[a[i]] - frnt - 1; j >= 0; --j) {
      const int ci = rem[j];
      p.emplace_back(frnt - 1 + rem.size());
      c.emplace_back(ci);
      rem.emplace_back(ci);
    }
    // REP(k, rem.size()) cout << rem[k] << " \n"[k + 1 == rem.size()];
    vector<int> nxt;
    FOR(j, pos[a[i]] - frnt + 1, rem.size()) {
      p.emplace_back(frnt - 1 + rem.size() + j);
      c.emplace_back(rem[j]);
      nxt.emplace_back(rem[j]);
    }
    // REP(k, nxt.size()) cout << nxt[k] << " \n"[k + 1 == nxt.size()];
    t.emplace_back(rem.size() * 2);
    frnt += rem.size() * 2;
    m = frnt;
    reverse(ALL(nxt));
    rem.swap(nxt);
    pos.clear();
    for (int e : rem) pos[e] = m++;
  }
  assert(rem.empty());
  const int q = p.size();
  cout << q << '\n';
  REP(i, q) cout << p[i] << ' ' << c[i] << '\n';
  const int d = t.size();
  cout << d << '\n';
  REP(i, d) cout << t[i] << " \n"[i + 1 == d];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}