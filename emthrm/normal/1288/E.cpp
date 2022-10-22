#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
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
  int n, m; cin >> n >> m;
  vector<int> a(m);
  vector<vector<int> > idx(n);
  REP(i, m) {
    cin >> a[i], --a[i];
    idx[a[i]].emplace_back(i);
  }
  vector<int> v(n, 0);
  BIT0based<int> bit(n);
  REP(i, m) {
    if (bit[a[i]] == 1) continue;
    v[a[i]] = bit.sum(a[i], n) + a[i];
    bit.add(a[i], 1);
  }
  REP(i, n) {
    if (bit[i] == 0) v[i] = bit.sum(i, n) + i;
  }
  vector<pair<pair<int, int>, int> > query;
  REP(i, n) {
    if (idx[i].empty()) continue;
    idx[i].emplace_back(m);
    REP(j, idx[i].size() - 1) {
      if (idx[i][j + 1] - idx[i][j] == 1) continue;
      if (idx[i][j + 1] - idx[i][j] == 2) chmax(v[i], 1);
      query.emplace_back(make_pair(idx[i][j + 1] - 1, idx[i][j] + 1), i);
    }
  }
  sort(ALL(query));
  vector<int> last(n, -1);
  BIT0based<int> bit2(m);
  int pos = -1;
  for (auto &e : query) {
    int l = e.first.second, r = e.first.first;
    while (pos < r) {
      ++pos;
      if (last[a[pos]] != -1) bit2.add(last[a[pos]], -1);
      last[a[pos]] = pos;
      bit2.add(pos, 1);
    }
    chmax(v[e.second], bit2.sum(l, r + 1));
  }
  REP(i, n) cout << (idx[i].empty() ? i + 1 : 1) << ' ' << v[i] + 1 << '\n';
  return 0;
}