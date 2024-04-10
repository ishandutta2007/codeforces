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
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

template <typename T = std::string>
struct SuffixArray {
  std::vector<int> sa, rank;

  SuffixArray(const T &s_) : s(s_) {
    int n = s.size();
    s.push_back(' ');
    sa.resize(n + 1);
    std::iota(sa.begin(), sa.end(), 0);
    std::sort(sa.begin(), sa.end(), [&](int a, int b) -> bool { return s[a] == s[b] ? a > b : s[a] < s[b]; });
    rank.resize(n + 1);
    for (int i = 0; i <= n; ++i) rank[i] = s[i];
    std::vector<int> tmp(n + 1), prev_sa(n + 1);
    for (int len = 1; len <= n; len <<= 1) {
      tmp[sa[0]] = 0;
      for (int i = 1; i <= n; ++i) {
        if (rank[sa[i - 1]] == rank[sa[i]] && sa[i - 1] + len <= n && rank[sa[i - 1] + (len >> 1)] == rank[sa[i] + (len >> 1)]) {
          tmp[sa[i]] = tmp[sa[i - 1]];
        } else {
          tmp[sa[i]] = i;
        }
      }
      rank.swap(tmp);
      std::iota(tmp.begin(), tmp.end(), 0);
      std::copy(sa.begin(), sa.end(), prev_sa.begin());
      for (int i = 0; i <= n; ++i) {
        int idx = prev_sa[i] - len;
        if (idx >= 0) sa[tmp[rank[idx]]++] = idx;
      }
    }
    for (int i = 0; i <= n; ++i) rank[sa[i]] = i;
  }

  std::vector<int> match(T &t) const {
    int lb = lower_bound(t);
    ++t.back();
    int ub = lower_bound(t);
    --t.back();
    std::vector<int> res(ub - lb);
    std::copy(sa.begin() + lb, sa.begin() + ub, res.begin());
    std::sort(res.begin(), res.end());
    return res;
  }

private:
  T s;

  int lower_bound(const T &t) const {
    int s_sz = s.size(), t_sz = t.size(), lb = 0, ub = s_sz;
    while (ub - lb > 1) {
      int mid = (lb + ub) >> 1, s_idx = sa[mid], t_idx = 0;
      bool finished = false;
      for (; s_idx < s_sz && t_idx < t_sz; ++s_idx, ++t_idx) {
        if (s[s_idx] != t[t_idx]) {
          (s[s_idx] < t[t_idx] ? lb : ub) = mid;
          finished = true;
          break;
        }
      }
      if (!finished) (s_idx == s_sz && t_idx < t_sz ? lb : ub) = mid;
    }
    return ub;
  }
};

template <typename MeetSemilattice>
struct SparseTable {
  using Fn = std::function<MeetSemilattice(MeetSemilattice, MeetSemilattice)>;

  SparseTable() {}

  SparseTable(const std::vector<MeetSemilattice> &a, Fn fn) { init(a, fn); }

  void init(const std::vector<MeetSemilattice> &a, Fn fn_) {
    is_built = true;
    fn = fn_;
    int n = a.size(), table_h = 0;
    lg.assign(n + 1, 0);
    for (int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
    while ((1 << table_h) <= n) ++table_h;
    dat.assign(table_h, std::vector<MeetSemilattice>(n));
    for (int j = 0; j < n; ++j) dat[0][j] = a[j];
    for (int i = 1; i < table_h; ++i) for (int j = 0; j + (1 << i) <= n; ++j) {
      dat[i][j] = fn(dat[i - 1][j], dat[i - 1][j + (1 << (i - 1))]);
    }
  }

  MeetSemilattice query(int left, int right) const {
    assert(is_built && left < right);
    int h = lg[right - left];
    return fn(dat[h][left], dat[h][right - (1 << h)]);
  }

private:
  bool is_built = false;
  Fn fn;
  std::vector<int> lg;
  std::vector<std::vector<MeetSemilattice>> dat;
};

template <typename T = std::string>
struct LCP : SuffixArray<T> {
  std::vector<int> lcp_array;

  LCP(const T &s) : SuffixArray<T>(s) {
    int n = s.size();
    lcp_array.resize(n);
    int common = 0;
    for (int i = 0; i < n; ++i) {
      int j = this->sa[this->rank[i] - 1];
      if (common > 0) --common;
      for (; i + common < n && j + common < n; ++common) {
        if (s[i + common] != s[j + common]) break;
      }
      lcp_array[this->rank[i] - 1] = common;
    }
    st.init(lcp_array, [](int a, int b) -> int { return std::min(a, b); });
  }

  int query(int i, int j) const {
    assert(i != j);
    i = this->rank[i];
    j = this->rank[j];
    if (i > j) std::swap(i, j);
    return st.query(i, j);
  }

private:
  SparseTable<int> st;
};

void solve() {
  int n, k; string s; cin >> n >> k >> s;
  for (char &c : s) c = c == '0' ? '1' : '0';
  LCP lcp(s);
  vector<int> a(n - k + 1);
  iota(ALL(a), 0);
  sort(ALL(a), [&](int l, int r) {
    int len = lcp.query(l, r);
    return len >= k ? false : s[l + len] < s[r + len];
  });
  vector<int> b;
  REP(i, n - k + 1) {
    if (b.empty() || lcp.query(b.back(), a[i]) < k) b.emplace_back(a[i]);
  }
  if (k < 20 && b.size() == (1 << k)) {
    cout << "NO\n";
    return;
  }
  vector<int> one(n, 0);
  for (int i = 0; i < n;) {
    if (s[i] == '1') {
      ++i;
      continue;
    }
    int j = i + 1;
    while (j < n && s[j] == '0') ++j;
    FOR(k, i, j) one[k] = j - k;
    i = j;
  }
  int l = k;
  string ans = string(k, '0');
  for (int f : b) {
    int p = min(one[f], l);
    FOR(i, p, k) {
      if (ans[i] != s[f + i]) {
        cout << "YES\n" << ans << '\n';
        return;
      }
    }
    ++ans.back();
    for (int i = k - 1; i >= 0; --i) {
      chmin(l, i);
      if (ans[i] < '2') break;
      // assert(i > 0);
      ans[i] = '0';
      ++ans[i - 1];
    }
  }
  cout << "YES\n" << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}