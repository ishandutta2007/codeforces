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

int main() {
  int n, k; string s; cin >> n >> k >> s;
  while (s.length() < k) s += s;
  s.resize(k);
  SuffixArray sa(s);
  int suf = k;
  FOR(i, sa.rank[0] + 1, k + 1) chmin(suf, sa.sa[i]);
  s = s.substr(0, suf);
  while (s.length() < k) s += s;
  s.resize(k);
  cout << s << '\n';
  return 0;
}