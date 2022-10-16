//  Copyright 2020 Nikita Golikov

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

  i64 const INF = (i64) 1e18;

  i64 x0, y0, ax, ay, bx, by;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by;
  i64 xs, ys, t;
  cin >> xs >> ys >> t;

  vector<pair<i64, i64>> pts{{x0, y0}};
  auto ok = [](i64 x, i64 a, i64 b) {
    if (x >= INF / a) return false;
    x *= a;
    if (x >= INF) return false;
    x += b;
    return x < INF;
  };
  auto dist = [](i64 x0, i64 y0, i64 x1, i64 y1) -> i64 {
    return llabs(x0 - x1) + llabs(y0 - y1);
  };
  while (ok(x0, ax, bx) && ok(y0, ay, by)) {
    x0 = x0 * ax + bx;
    y0 = y0 * ay + by;
    pts.emplace_back(x0, y0);
  }
  int ans = 0;
  int k = (int) pts.size();
  for (int rot = 0; rot < 2; ++rot) {
    for (int i = 0; i < k; ++i) {
      i64 cur_x = xs;
      i64 cur_y = ys;
      int c = 0;
      i64 dst = 0;
      for (int j = i; j < k; ++j) {
        auto dlt = dist(cur_x, cur_y, pts[j].first, pts[j].second);
        if (dlt + dst > t) break;
        dst += dlt;
        ++c;
        tie(cur_x, cur_y) = pts[j];
      }
      set_max(ans, c);
    }
    reverse(pts.begin(), pts.end());
  }
  cout << ans << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
          chrono::high_resolution_clock::now() - _clock_start).count() << "ms."
       << endl;
#endif
  return 0;
}