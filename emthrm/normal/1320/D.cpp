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

template <typename MeetSemilattice>
struct SparseTable {
  using Fn = function<MeetSemilattice(MeetSemilattice, MeetSemilattice)>;

  SparseTable() {}

  SparseTable(const vector<MeetSemilattice> &a, Fn fn, MeetSemilattice UNITY = 0) { init(a, fn); }

  void init(const vector<MeetSemilattice> &a, Fn fn_) {
    fn = fn_;
    int n = a.size(), table_h = 0;
    lg.assign(n + 1, 0);
    FOR(i, 2, n + 1) lg[i] = lg[i >> 1] + 1;
    while ((1 << table_h) <= n) ++table_h;
    dat.assign(table_h, vector<MeetSemilattice>(n));
    REP(j, n) dat[0][j] = a[j];
    FOR(i, 1, table_h) for (int j = 0; j + (1 << i) <= n; ++j) {
      dat[i][j] = fn(dat[i - 1][j], dat[i - 1][j + (1 << (i - 1))]);
    }
  }

  MeetSemilattice query(int left, int right) {
    assert(left < right);
    int h = lg[right - left];
    return fn(dat[h][left], dat[h][right - (1 << h)]);
  }

private:
  Fn fn;
  vector<int> lg;
  vector<vector<MeetSemilattice> > dat;
};

template <typename T = string>
struct SuffixArray {
  vector<int> sa, rank, lcp_array;

  SuffixArray(const T &s, bool heavy = false) : str(s), heavy(heavy) {
    int n = str.size();
    str.push_back(' ');
    sa.resize(n + 1);
    iota(ALL(sa), 0);
    sort(ALL(sa), [&](int a, int b) { return s[a] == s[b] ? a > b : s[a] < s[b]; });
    rank.resize(n + 1);
    REP(i, n + 1) rank[i] = s[i];
    vector<int> tmp_rank(n + 1), tmp_sa(n + 1), cnt(n + 1);
    for (int len = 1; len <= n; len <<= 1) {
      REP(i, n + 1) {
        if (i > 0 && rank[sa[i - 1]] == rank[sa[i]] && sa[i - 1] + len <= n && rank[sa[i - 1] + (len >> 1)] == rank[sa[i] + (len >> 1)]) {
          tmp_rank[sa[i]] = tmp_rank[sa[i - 1]];
        } else {
          tmp_rank[sa[i]] = i;
        }
      }
      copy(ALL(sa), tmp_sa.begin());
      iota(ALL(cnt), 0);
      REP(i, n + 1) {
        int idx = tmp_sa[i] - len;
        if (idx >= 0) sa[cnt[tmp_rank[idx]]++] = idx;
      }
      rank.swap(tmp_rank);
    }
    REP(i, n + 1) rank[sa[i]] = i;
    if (heavy) {
      lcp_array.resize(n);
      int common = 0;
      REP(i, n) {
        int j = sa[rank[i] - 1];
        if (common > 0) --common;
        for (; i + common < n && j + common < n; ++common) {
          if (str[i + common] != str[j + common]) break;
        }
        lcp_array[rank[i] - 1] = common;
      }
      st.init(lcp_array, [](int a, int b) { return min(a, b); });
    }
  }

  vector<int> match(T &t) {
    int lb = lower_bound(t);
    ++t.back();
    int ub = lower_bound(t);
    --t.back();
    vector<int> res(ub - lb);
    copy(sa.begin() + lb, sa.begin() + ub, res.begin());
    sort(ALL(res));
    return res;
  }

  int lcp(int i, int j) {
    // assert(heavy && i != j);
    i = rank[i];
    j = rank[j];
    if (i > j) swap(i, j);
    return st.query(i, j);
  }

private:
  bool heavy;
  T str;
  SparseTable<int> st;

  int lower_bound(const T &t) {
    int str_sz = str.size(), t_sz = t.size(), lb = 0, ub = str_sz;
    while (ub - lb > 1) {
      int mid = (lb + ub) >> 1, str_idx = sa[mid], t_idx = 0;
      bool finished = false;
      for (; str_idx < str_sz && t_idx < t_sz; ++str_idx, ++t_idx) {
        if (str[str_idx] != t[t_idx]) {
          (str[str_idx] < t[t_idx] ? lb : ub) = mid;
          finished = true;
          break;
        }
      }
      if (!finished) (str_idx == str_sz && t_idx < t_sz ? lb : ub) = mid;
    }
    return ub;
  }
};

int main() {
  int n, q; string t; cin >> n >> t >> q;
  vector<int> zero_pos;
  REP(i, n) {
    if (t[i] == '0') zero_pos.emplace_back(i);
  }
  if (zero_pos.empty()) {
    while (q--) cout << "Yes\n";
    return 0;
  }
  string one = "";
  one += '0' + (zero_pos.front() & 1);
  REP(i, int(zero_pos.size()) - 1) one += '0' + ((zero_pos[i + 1] - zero_pos[i] - 1) & 1);
  one += '0' + ((n - zero_pos.back() - 1) & 1);
  // cout << one << '\n';
  SuffixArray<> one_sa(one, true);
  vector<int> cnt(n + 1, 0);
  REP(i, n) cnt[i + 1] = t[i] == '0';
  FOR(i, 1, n + 1) cnt[i] += cnt[i - 1];
  while (q--) {
    int l1, l2, len; cin >> l1 >> l2 >> len; --l1; --l2;
    if (l1 > l2) swap(l1, l2);
    if (cnt[l1 + len] - cnt[l1] != cnt[l2 + len] - cnt[l2]) {
      cout << "No\n";
      continue;
    }
    if (cnt[l1 + len] - cnt[l1] == 0) {
      cout << "Yes\n";
      continue;
    }
    int fr_l1 = lower_bound(ALL(zero_pos), l1) - zero_pos.begin(), ba_l1 = prev(lower_bound(ALL(zero_pos), l1 + len)) - zero_pos.begin();
    int fr_l2 = lower_bound(ALL(zero_pos), l2) - zero_pos.begin(), ba_l2 = prev(lower_bound(ALL(zero_pos), l2 + len)) - zero_pos.begin();
    if (fr_l1 < ba_l1) {
      if (fr_l1 < fr_l2 && one_sa.lcp(fr_l1 + 1, fr_l2 + 1) < ba_l1 - fr_l1) {
        cout << "No\n";
        continue;
      }
    }
    fr_l1 = zero_pos[fr_l1];
    ba_l1 = zero_pos[ba_l1];
    fr_l2 = zero_pos[fr_l2];
    ba_l2 = zero_pos[ba_l2];
    // cout << fr_l1 << ' ' << ba_l1 << ' ' << fr_l2 << ' ' << ba_l2 << '\n';
    cout << ((fr_l1 - l1) % 2 == (fr_l2 - l2) % 2 && (l1 + len - ba_l1 - 1) % 2 == (l2 + len - ba_l2 - 1) % 2 ? "Yes\n" : "No\n");
  }
  return 0;
}