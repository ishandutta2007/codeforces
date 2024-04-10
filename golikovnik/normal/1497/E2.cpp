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

int const N = int(1e7 + 5);
int prime[N];
int sqfree[N];
int mp[N];

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& x : a) {
    cin >> x;
    x = sqfree[x];
  }
  vector<vector<int>> nxt(k + 1, vector<int>(n));
  for (int cnt = 0; cnt <= k; ++cnt) {
    for (int x : a) mp[x] = 0;

    int curCnt = 0;
    auto tryAdd = [&](int x) {
      int newCnt = curCnt + !!mp[x];
      if (newCnt > cnt) return false;
      mp[x]++;
      curCnt = newCnt;
      return true;
    };
    auto remove = [&](int x) {
      curCnt -= (mp[x] >= 2);
      mp[x]--;
    };

    int r = -1;
    for (int l = 0; l < n; ++l) {
      while (r + 1 < n && tryAdd(a[r + 1])) ++r;
      nxt[cnt][l] = r;
      remove(a[l]);
    }
  }

  vector<vector<int>> dp(n + 1, vector<int>(k + 1, n));
  dp[n][0] = 0;
  for (int i = n - 1; i >= 0; --i) {
    for (int use = 0; use <= k; ++use) {
      for (int me = 0; me <= use; ++me) {
        dp[i][use] = min(dp[i][use],
          1 + dp[nxt[me][i] + 1][use - me]);
      }
    }
  }
  cout << *min_element(dp[0].begin(), dp[0].end()) << '\n';
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  sqfree[1] = 1;
  for (int p = 2; p < N; ++p) {
    if (prime[p] == 0) {
      for (int p2 = p; p2 < N; p2 += p) {
        prime[p2] = p;
      }
    }
    int pr = prime[p];
    int sqf = sqfree[p / pr];
    if (sqf % pr == 0) {
      sqf /= pr;
    } else {
      sqf *= pr;
    }
    sqfree[p] = sqf;
  }

  int t;
  cin >> t;
  while (t--) solve();

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}