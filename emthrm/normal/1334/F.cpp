#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

template <typename Abelian>
struct BIT0based {
  BIT0based(int n, const Abelian UNITY = 0) : n(n), UNITY(UNITY), dat(n, UNITY) {}

  void add(int idx, Abelian val) {
    while (idx < n) {
      dat[idx] += val;
      idx |= idx + 1;
    }
  }

  Abelian sum(int idx) {
    Abelian res = UNITY;
    --idx;
    while (idx >= 0) {
      res += dat[idx];
      idx = (idx & (idx + 1)) - 1;
    }
    return res;
  }

  Abelian sum(int left, int right) {
    if (right <= left) return UNITY;
    return sum(right) - sum(left);
  }

  Abelian operator[](const int idx) { return sum(idx, idx + 1); }

  int lower_bound(Abelian val) {
    if (val <= UNITY) return 0;
    int res = 0, exponent = 1;
    while (exponent <= n) exponent <<= 1;
    for (int mask = exponent >> 1; mask > 0; mask >>= 1) {
      if (res + mask - 1 < n && dat[res + mask - 1] < val) {
        val -= dat[res + mask - 1];
        res += mask;
      }
    }
    return res;
  }

private:
  int n;
  const Abelian UNITY;
  vector<Abelian> dat;
};

int main() {
  int n; cin >> n;
  vector<int> a(n), p(n);
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> p[i];
  int m; cin >> m;
  vector<int> b(m); REP(i, m) cin >> b[i];
  {
    int idx = 0;
    REP(i, n) {
      if (idx < m && a[i] == b[idx]) ++idx;
    }
    if (idx < m) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  a.emplace(a.begin(), 0);
  a.emplace_back(INF);
  p.emplace(p.begin(), 0);
  p.emplace_back(0);
  n += 2;
  b.emplace(b.begin(), 0);
  b.emplace_back(INF);
  m += 2;
  vector<vector<int>> idx(m);
  REP(i, n) {
    int pos = lower_bound(ALL(b), a[i]) - b.begin();
    if (b[pos] == a[i]) idx[pos].emplace_back(i);
  }
  BIT0based<ll> bit(n);
  REP(i, n) bit.add(i, p[i]);
  vector<pair<int, int>> sor(n);
  REP(i, n) sor[i] = {a[i], i};
  sort(ALL(sor));
  int sor_pos = 0;
  vector<vector<ll>> dp(m);
  dp[0] = {0};
  FOR(i, 1, m) {
    int sz = idx[i].size();
    REP(j, sz) {
      int it = lower_bound(ALL(idx[i - 1]), idx[i][j]) - idx[i - 1].begin() - 1;
      dp[i].emplace_back(it < 0 ? LINF : dp[i - 1][it] + bit.sum(idx[i - 1][it] + 1, idx[i][j]));
    }
    while (sor_pos < n && sor[sor_pos].first <= b[i]) {
      int pos = sor[sor_pos++].second;
      if (p[pos] > 0) bit.add(pos, -p[pos]);
    }
    FOR(j, 1, sz) chmin(dp[i][j], dp[i][j - 1] + bit.sum(idx[i][j - 1] + 1, idx[i][j] + 1));
  }
  cout << dp[m - 1][0] << '\n';
  return 0;
}