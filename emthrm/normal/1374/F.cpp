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

  Abelian sum(int idx) const {
    Abelian res = UNITY;
    --idx;
    while (idx >= 0) {
      res += dat[idx];
      idx = (idx & (idx + 1)) - 1;
    }
    return res;
  }

  Abelian sum(int left, int right) const {
    if (right <= left) return UNITY;
    return sum(right) - sum(left);
  }

  Abelian operator[](const int idx) const { return sum(idx, idx + 1); }

  int lower_bound(Abelian val) const {
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

template <typename T>
ll inversion_number(const vector<T> &a) {
  int n = a.size();
  vector<T> comp(a);
  sort(ALL(comp));
  comp.erase(unique(ALL(comp)), comp.end());
  BIT0based<int> bit(comp.size());
  ll res = 0;
  REP(i, n) {
    int idx = lower_bound(ALL(comp), a[i]) - comp.begin();
    res += i - bit.sum(idx);
    bit.add(idx, 1);
  }
  return res;
}

void solve() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<int> idx(n);
  iota(ALL(idx), 0);
  stable_sort(ALL(idx), [&](int l, int r) { return a[l] < a[r]; });
  if (inversion_number(idx) & 1) {
    bool is_odd = true;
    REP(i, n) FOR(j, i + 1, n) {
      if (is_odd && a[i] == a[j]) {
        int l = find(ALL(idx), i) - idx.begin(), r = find(ALL(idx), j) - idx.begin();
        assert(l < r);
        swap(idx[l], idx[r]);
        is_odd = false;
      }
    }
    if (is_odd) {
      cout << "-1\n";
      return;
    }
  }
  // REP(i, n) cout << idx[i] << " \n"[i + 1 == n];
  REP(i, n) a[idx[i]] = i;
  vector<int> ans;
  function<void(int)> ope = [&](int pos) {
    assert(2 <= pos && pos < n);
    ans.emplace_back(pos - 2);
    swap(a[pos - 1], a[pos]);
    swap(a[pos - 2], a[pos - 1]);
  };
  for (int val = n - 1; val >= 2; --val) {
    REP(i, val + 1) {
      if (a[i] == val) {
        if (i == 0) {
          ++i;
          ope(2);
        }
        FOR(j, i + 1, val + 1) ope(j);
        break;
      }
    }
  }
  assert(is_sorted(ALL(a)));
  int m = ans.size();
  cout << m << '\n';
  REP(i, m) cout << ans[i] + 1 << " \n"[i + 1 == m];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}