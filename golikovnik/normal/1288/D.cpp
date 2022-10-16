#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

#ifdef GOLIKOV
mt19937_64 rng(566);
#else
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif

template <typename T>
T rnd_helper(T from, T to, true_type) {
  return uniform_int_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd_helper(T from, T to, false_type) {
  return uniform_real_distribution<T>(from, to)(rng);
}

template <typename T>
T rnd(T from, T to) {
  return rnd_helper(from, to, is_integral<T>{});
}

template <typename A, typename B, typename Cmp>
bool set_min(A& x, B const& y, Cmp&& cmp) {
  if (cmp(y, x)) {
    x = y;
    return true;
  }
  return false;
}

template <typename A, typename B>
bool set_min(A& x, B const& y) {
  return set_min(x, y, less<>{});
}

template <typename A, typename B>
bool set_max(A& x, B const& y) {
  return set_min(x, y, greater<>{});
}

int main() {
#ifdef GOLIKOV
  freopen("in", "rt", stdin);
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (auto& r : a) for (auto& x : r) cin >> x;

  int left = -1;
  int right = (int) 1e9 + 1;
  pair<int, int> ans;

  int const MASK = 1 << m;
  int const U = MASK - 1;

  while (left + 1 != right) {
    int mid = (left + right) / 2;
    vector<int> have(MASK, -1);
    for (int i = 0; i < n; ++i) {
      int msk = 0;
      for (int j = 0; j < m; ++j) {
        msk <<= 1;
        msk += a[i][j] >= mid;
      }
      have[msk] = i;
    }
    bool ok = false;
    for (int m1 = 0; !ok && m1 < MASK; ++m1) {
      if (!~have[m1]) continue;
      auto comp = U ^ m1;
      for (int m2 = comp; ; ++m2 |= comp) {
        if (~have[m2]) {
          ok = true;
          ans = {have[m1], have[m2]};
          break;
        }
        if (m2 == U) break;
      }
    }
    (ok ? left : right) = mid;
  }
  cout << ans.first + 1 << ' ' << ans.second + 1 << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
            chrono::high_resolution_clock::now() - _clock_start
          ).count() << "ms.\n";
#endif
  return 0;
}