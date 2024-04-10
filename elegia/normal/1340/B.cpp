#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v)
    is >> x;
  return is;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<vector<int>> digits = {
          {1, 2, 3, 5, 6, 7},
          {3, 6},
          {1, 3, 4, 5, 7},
          {1, 3, 4, 6, 7},
          {2, 3, 4, 6},
          {1, 2, 4, 6, 7},
          {1, 2, 4, 5, 6, 7},
          {1, 3, 6},
          {1, 2, 3, 4, 5, 6, 7},
          {1, 2, 3, 4, 6, 7}
  };

  vector<int> mask(10);
  for (int i = 0; i < 10; ++i) {
    for (int v : digits[i])
      mask[i] |= 1 << (v - 1);
  }

  int n, k;
  cin >> n >> k;
  vector<int> board(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < 7; ++j)
      if (s[j] == '1')
        board[i] |= 1 << j;
  }
  vector<bitset<2020>> dp(n + 1);
  dp[n].set(0);
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 10; ++j)
      if ((mask[j] & board[i]) == board[i])
        dp[i] |= dp[i + 1] << (__builtin_popcount(mask[j]) - __builtin_popcount(board[i]));
  }
  if (!dp[0][k]) {
    cout << "-1\n";
    return 0;
  }
  string ans;
  for (int i = 0; i < n; ++i) {
    for (int j = 9;; --j)
      if ((mask[j] & board[i]) == board[i]) {
        int x = __builtin_popcount(mask[j]) - __builtin_popcount(board[i]);
        if (x <= k && dp[i + 1][k - x]) {
          ans.push_back(j + '0');
          k -= x;
          break;
        }
      }
  }
  cout << ans;

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}