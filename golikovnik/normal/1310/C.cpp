//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

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

  int n, m;
  ll k;
  cin >> n >> m >> k;
  string s; cin >> s;
  vector<pair<int, int>> substrings;
  substrings.reserve(n * (n + 1) / 2);
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i <= j; ++i) {
      substrings.emplace_back(i, j);
    }
  }
  vector lcp(n + 1, vector<int>(n + 1));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (s[i] == s[j]) {
        lcp[i][j] = 1 + lcp[i + 1][j + 1];
      }
    }
  }

  sort(substrings.begin(), substrings.end(), [&](auto x, auto y) {
    auto[ix, jx] = x;
    auto[iy, jy] = y;
    int lx = jx - ix + 1;
    int ly = jy - iy + 1;
    int l = lcp[ix][iy];
    auto endx = l >= lx;
    auto endy = l >= ly;
    if (endx && endy) {
      return lx > ly;
    }
    if (endx) {
      return false;
    }
    if (endy) {
      return true;
    }
    return s[ix + l] > s[iy + l];
  });

  auto add = [k](ll x, ll y) {
    return min(k, x + y);
  };

  vector dp(n + 2, vector<ll>(m + 1));
  vector actualdp(n + 2, vector<ll>(m + 1));
  auto calc = [&](int from, int to) {
    int len = to - from + 1;

    for (int i = 0; i <= m; ++i) {
      dp[n][i] = dp[n + 1][i] = 0;
    }
    dp[n][0] = 1;

    for (int i = n - 1; i >= 0; --i) {
      int l = lcp[i][from];
      int lenme = n - i;

      bool diff = l < lenme && l < len;
      int L;
      if (diff) {
        if (s[i + l] > s[from + l]) {
          L = i + l + 1;
        } else {
          L = n + 1;
        }
      } else {
        if (lenme >= len) {
          L = i + len;
        } else {
          L = n + 1;
        }
      }

      for (int cnt = 1; cnt <= m; ++cnt) {
        ll v = dp[L][cnt - 1];
        actualdp[i][cnt] = v;
        dp[i][cnt] = add(v, dp[i + 1][cnt]);
      }

      dp[i][0] = 1;
    }

    return actualdp[0][m];
  };

  int left = -1;
  int right = int(substrings.size()) - 1;
  while (left + 1 != right) {
    int mid = (left + right) / 2;
    auto[i, j] = substrings[mid];
    auto cnt = calc(i, j);
    (cnt >= k ? right : left) = mid;
  }
  auto[i, j] = substrings[right];
  cout << s.substr(i, j - i + 1) << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}