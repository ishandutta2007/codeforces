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

template <typename T = std::string>
struct SuffixArray {
  std::vector<int> sa, rank;

  template <typename U = char>
  explicit SuffixArray(const T& s_, const U sentinel = 0) : s(s_) {
    const int n = s.size();
    s.push_back(sentinel);
    sa.resize(n + 1);
    std::iota(sa.begin(), sa.end(), 0);
    std::sort(sa.begin(), sa.end(), [this](const int a, const int b) -> bool {
      return s[a] == s[b] ? a > b : s[a] < s[b];
    });
    rank.resize(n + 1);
    for (int i = 0; i <= n; ++i) {
      rank[i] = s[i];
    }
    std::vector<int> tmp(n + 1), prev_sa(n + 1);
    for (int len = 1; len <= n; len <<= 1) {
      tmp[sa[0]] = 0;
      for (int i = 1; i <= n; ++i) {
        if (rank[sa[i - 1]] == rank[sa[i]] && sa[i - 1] + len <= n &&
            rank[sa[i - 1] + (len >> 1)] == rank[sa[i] + (len >> 1)]) {
          tmp[sa[i]] = tmp[sa[i - 1]];
        } else {
          tmp[sa[i]] = i;
        }
      }
      rank.swap(tmp);
      std::iota(tmp.begin(), tmp.end(), 0);
      std::copy(sa.begin(), sa.end(), prev_sa.begin());
      for (int i = 0; i <= n; ++i) {
        const int idx = prev_sa[i] - len;
        if (idx >= 0) sa[tmp[rank[idx]]++] = idx;
      }
    }
    for (int i = 0; i <= n; ++i) {
      rank[sa[i]] = i;
    }
  }

  std::vector<int> match(T* t) const {
    const int lb = lower_bound(t);
    ++t->back();
    const int ub = lower_bound(t);
    --t->back();
    std::vector<int> res(ub - lb);
    std::copy(sa.begin() + lb, sa.begin() + ub, res.begin());
    std::sort(res.begin(), res.end());
    return res;
  }

 private:
  T s;

  int lower_bound(const T* t) const {
    const int s_size = s.size(), t_size = t->size();
    int lb = 0, ub = s_size;
    while (ub - lb > 1) {
      const int mid = (lb + ub) >> 1;
      int s_idx = sa[mid], t_idx = 0;
      bool finished = false;
      for (; s_idx < s_size && t_idx < t_size; ++s_idx, ++t_idx) {
        if (s[s_idx] != (*t)[t_idx]) {
          (s[s_idx] < (*t)[t_idx] ? lb : ub) = mid;
          finished = true;
          break;
        }
      }
      if (!finished) (s_idx == s_size && t_idx < t_size ? lb : ub) = mid;
    }
    return ub;
  }
};

// https://twitter.com/maspy_stars/status/1505543836570828800
int main() {
  int n; string s; cin >> n >> s;
  vector<int> ans(1 << n);
  iota(ALL(ans), 0);
  sort(ALL(ans), [&](int i, int j) -> bool { return s[i] < s[j]; });
  vector<int> v(1 << n, 0);
  FOR(i, 1, 1 << n) v[ans[i]] = v[ans[i - 1]] + (s[ans[i - 1]] < s[ans[i]]);
  for (int len = 1; len < (1 << n); len <<= 1) {
    auto cmp = [&](int i, int j) -> bool {
      return v[i] != v[j] ? v[i] < v[j] : v[i ^ len] < v[j ^ len];
    };
    sort(ALL(ans), cmp);
    vector<int> nxt(1 << n, 0);
    FOR(i, 1, 1 << n) nxt[ans[i]] = nxt[ans[i - 1]] + cmp(ans[i - 1], ans[i]);
    v.swap(nxt);
  }
  REP(i, 1 << n) cout << s[i ^ ans.front()];
  cout << '\n';
  return 0;
}