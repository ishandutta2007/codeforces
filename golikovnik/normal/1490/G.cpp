//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

void solve(int) {
  int n, m;
  cin >> n >> m;
  i64 sum = 0;
  vector<pair<i64, int>> pref_max;
  i64 mx = 0;
  pref_max.emplace_back(0, 0);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    sum += x;
    if (smax(mx, sum)) {
      pref_max.emplace_back(sum, i + 1);
    }
  }
  while (m--) {
    i64 s;
    cin >> s;
    if (sum <= 0 && s > mx) {
      cout << -1 << ' ';
      continue;
    }
    //  sum * k + mx >= s
    //  sum * k >= s - mx
    auto iters = sum <= 0 ? 0 : max(i64(0), (s - mx + sum - 1) / sum);
    i64 ans = iters * n;
    s -= iters * sum;
    auto it = lower_bound(pref_max.begin(), pref_max.end(),
                          make_pair(s, 0));
    ans += it->second;
    cout << (ans - 1) << ' ';
  }
  cout << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests;
  cin >> tests;
  for (int _tt = 1; _tt <= tests; ++_tt) {
    solve(_tt);
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}