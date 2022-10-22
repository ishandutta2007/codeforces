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

int main() {
  int n, m, k; cin >> n >> m >> k;
  vector<int> t(n), a, b, both, nei;
  REP(i, n) {
    int ai, bi; cin >> t[i] >> ai >> bi;
    if (ai == 0 && bi == 0) {
      nei.emplace_back(i);
    } else if (ai == 0 && bi == 1) {
      b.emplace_back(i);
    } else if (ai == 1 && bi == 0) {
      a.emplace_back(i);
    } else if (ai == 1 && bi == 1) {
      both.emplace_back(i);
    }
  }
  const int X = 10000;
  BIT0based<int> cnt(X + 1);
  BIT0based<ll> sum(X + 1);
  function<void(int)> add = [&](int idx) {
    cnt.add(t[idx], 1);
    sum.add(t[idx], t[idx]);
  };
  function<void(int)> era = [&](int idx) {
    cnt.add(t[idx], -1);
    sum.add(t[idx], -t[idx]);
  };
  function<ll(int)> query = [&](int book) {
    if (book == 0) return 0LL;
    if (cnt.sum(X + 1) < book) return LINF;
    int ub = cnt.lower_bound(book);
    return sum.sum(ub) + 1LL * ub * (book - cnt.sum(ub));
  };
  vector<int> init;
  sort(ALL(a), [&](int l, int r) { return t[l] < t[r]; });
  while (a.size() > k) {
    add(a.back());
    init.emplace_back(a.back());
    a.pop_back();
  }
  // REP(i, a.size()) cout << a[i] << " \n"[i + 1 == a.size()];
  ll a_sum = 0;
  for (int idx : a) a_sum += t[idx];
  sort(ALL(b), [&](int l, int r) { return t[l] < t[r]; });
  while (b.size() > k) {
    add(b.back());
    init.emplace_back(b.back());
    b.pop_back();
  }
  // REP(i, b.size()) cout << b[i] << " \n"[i + 1 == b.size()];
  ll b_sum = 0;
  for (int idx : b) b_sum += t[idx];
  sort(ALL(both), [&](int l, int r) { return t[l] < t[r]; });
  while (both.size() > k) {
    add(both.back());
    init.emplace_back(both.back());
    both.pop_back();
  }
  // REP(i, both.size()) cout << both[i] << " \n"[i + 1 == both.size()];
  for (int idx : both) add(idx);
  for (int idx : nei) {
    init.emplace_back(idx);
    add(idx);
  }
  // for (int e : init) cout << e << ' ';
  ll ans = LINF;
  int memo = -1;
  if (a.size() == k && b.size() == k && k + k <= m) {
    ll tmp = a_sum + b_sum + query(m - k - k);
    if (ans > tmp) {
      ans = tmp;
      memo = 0;
    }
  }
  int a_sz = a.size(), b_sz = b.size();
  ll both_sum = 0;
  for (int i = 0; i < both.size(); ++i) {
    if (a_sz == k - i) {
      --a_sz;
      add(a[a_sz]);
      a_sum -= t[a[a_sz]];
    }
    if (b_sz == k - i) {
      --b_sz;
      add(b[b_sz]);
      b_sum -= t[b[b_sz]];
    }
    era(both[i]);
    both_sum += t[both[i]];
    if (a_sz == k - 1 - i && b_sz == k - 1 - i && k * 2 - (i + 1) <= m) {
      ll tmp = both_sum + a_sum + b_sum + query(m - (k * 2 - (i + 1)));
      if (ans > tmp) {
        ans = tmp;
        memo = i + 1;
      }
    }
  }
  if (memo == -1) {
    cout << "-1\n";
    return 0;
  }
  cout << ans << '\n';
  FOR(i, memo, both.size()) init.emplace_back(both[i]);
  FOR(i, k - memo, a.size()) init.emplace_back(a[i]);
  FOR(i, k - memo, b.size()) init.emplace_back(b[i]);
  sort(ALL(init), [&](int l, int r) { return t[l] > t[r]; });
  vector<int> books;
  REP(i, k - memo) books.emplace_back(a[i]);
  REP(i, k - memo) books.emplace_back(b[i]);
  REP(i, memo) books.emplace_back(both[i]);
  while (books.size() < m) {
    books.emplace_back(init.back());
    init.pop_back();
  }
  REP(i, m) cout << books[i] + 1 << " \n"[i + 1 == m];
  return 0;
}