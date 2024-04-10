#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

const int N = 18;
int g[N][N];
ll dp[1 << N][N];
ll ways[1 << N][N + 1];
ll cnt[1 << N];
ll ans[1 << N];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c;
      cin >> c;
      g[i][j] = c - '0';
    }
  }
  for (int i = 0; i < n; ++i) {
    dp[1 << i][i] = 1;
  }   
  for (int mask = 1; mask < (1 << n); ++mask) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (g[i][j] && !(mask & (1 << j))) {
          dp[mask | (1 << j)][j] += dp[mask][i];
        }
      }
    }
  }
  for (int mask = 1; mask < (1 << n); ++mask) {
    for (int i = 0; i < n; ++i) {
      ways[mask][__builtin_popcount(mask)] += dp[mask][i];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int mask = 0; mask < (1 << n); ++mask) {
        if (mask & (1 << j)) {
          ways[mask][i] += ways[mask ^ (1 << j)][i];
        }
      }
    }
  }
  map <vector <int>, vector <int>> gs;
  for (int mask = 0; mask < (1 << (n - 1)); ++mask) {
    int len = 1;
    vector <int> cur;
    for (int i = 0; i < n - 1; ++i) {
      if (mask & (1 << i)) {
        ++len;
      } else {
        cur.push_back(len);
        len = 1;
      }
    }
    cur.push_back(len);
    sort(cur.begin(), cur.end());
    gs[cur].push_back(mask);
  }
  for (auto p : gs) {
    fill(cnt, cnt + (1 << n), 1);
    for (int mask = 0; mask < (1 << n); ++mask) {
      for (int x : p.first) {
        cnt[mask] *= ways[mask][x];
      }
    }
    ll res = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
      if ((__builtin_popcount(mask) % 2) == (__builtin_popcount((1 << n) - 1) % 2)) {
        res += cnt[mask];
      } else {
        res -= cnt[mask];
      }
    }
    for (int id : p.second) {
      ans[id] += res;
    }
  }
  for (int i = 0; i + 1 < n; ++i) {
    for (int mask = 0; mask < (1 << (n - 1)); ++mask) {
      if (!(mask & (1 << i))) {
        ans[mask] -= ans[mask | (1 << i)];
      }
    }
  }
  for (int mask = 0; mask < (1 << (n - 1)); ++mask) {
    cout << ans[mask] << ' ';
  }
}