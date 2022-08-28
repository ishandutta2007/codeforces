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

  int t;
  cin >> t;
  while (t--) {
    int n;
    string a, b;
    cin >> n >> a >> b;
    {
      string x = a, y = b;
      sort(x.begin(), x.end());
      sort(y.begin(), y.end());
      if (x != y) {
        cout << "-1\n";
        continue;
      }
    }
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
      vector<int> cnt(26);
      for (int j = 0; j < i; ++j) {
        --cnt[a[j] - 'a'];
        ++cnt[b[j] - 'a'];
        dp[i][j] = numeric_limits<int>::min();
      }
      int cntbad = 0;
      for (int j = 0; j < 26; ++j)
        if (cnt[j] < 0)
          ++cntbad;
      for (int j = i; j <= n; ++j) {
        if (!cntbad && a[i - 1] == b[j - 1])
          ans = max(ans, dp[i][j] = dp[i - 1][j - 1] + 1);
        if (!cntbad)
          dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i][j - 1]});
        else
          dp[i][j] = numeric_limits<int>::min();
        if (j < n) {
          if (++cnt[b[j] - 'a'] == 0)
            --cntbad;
        }
      }
    }
    cout << (n - ans) << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}