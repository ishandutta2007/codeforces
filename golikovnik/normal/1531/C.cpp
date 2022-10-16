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

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> dp(n + 1, n + 20);
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int take = 1; take <= i; take += 2) {
      int side = (take + 1) / 2;
      int left = i - take;
      if (dp[left] < side) {
        dp[i] = side;
        break;
      }
    }
  }

  if (dp[n] > n + 5) {
    cout << -1 << '\n';
    return 0;
  } else {
    cout << dp[n] << '\n';
  }

  int cur = n;
  int side = dp[cur];
  vector ans(side, string(side, '.'));
  for (int i = 0; cur > 0; ++i) {
    int take = dp[cur];
    for (int j = 0; j < take; ++j) {
      ans[side - 1 - i - j][i] = 'o';
      ans[side - 1 - i][i + j] = 'o';
    }
    cur -= (2 * take - 1);
  }
  for (auto const& s : ans) {
    cout << s << '\n';
  }

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}