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

template <class T>
bool chkMax(T& x, const T& y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

template <class T>
void chkMin(T& x, const T& y) {
  if (x > y) x = y;
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    if (n == k) {
      vector<pair<int, int>> q(n);
      vector<int> ans;
      for (int i = 0; i < n; ++i) q[i] = make_pair(b[i], i);
      sort(q.begin(), q.end());
      for (int i = 0; i < n; ++i) ans.push_back(q[i].second + 1);
      cout << n << '\n' << ans << '\n';
      continue;
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, numeric_limits<int>::min()));
    vector<vector<bool>> take(n + 1, vector<bool>(k + 1));
    dp[0][0] = 0;
    vector<tuple<int, int, int>> q(n);
    for (int i = 0; i < n; ++i) q[i] = make_tuple(b[i], a[i], i);
    sort(q.begin(), q.end());
    for (int i = 0; i < n; ++i) {
      int x = get<1>(q[i]), y = get<0>(q[i]);
      for (int j = 0; j <= k; ++j) {
        dp[i + 1][j] = dp[i][j] + (k - 1) * y;
      }
      for (int j = 0; j < k; ++j)
        if (chkMax(dp[i + 1][j + 1], dp[i][j] + j * y + x))
          take[i + 1][j + 1] = true;
    }
    vector<int> seq;
    int ck = k;
    vector<bool> vis(n);
    for (int i = n; i; --i)
      if (take[i][ck]) {
        seq.push_back(i - 1);
        vis[get<2>(q[i - 1])] = true;
        --ck;
      }
    reverse(seq.begin(), seq.end());
    vector<int> ans;
    for (int i = 0; i < k - 1; ++i)
      ans.push_back(get<2>(q[seq[i]]) + 1);
    for (int i = 0; i < n; ++i)
      if (!vis[i]) {
        ans.push_back(i + 1);
        ans.push_back(-i - 1);
      }
    ans.push_back(get<2>(q[seq.back()]) + 1);
    cout << ans.size() << '\n' << ans << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}