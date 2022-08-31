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

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int C = 614;

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<bool>> g(n, vector<bool>(n));
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    for (int j = 0; j < n; j += 4) {
      int dig = isdigit(s[j >> 2]) ? (s[j >> 2] - '0') : (s[j >> 2] - 'A' + 10);
      g[i][j] = (dig >> 3) & 1;
      g[i][j | 1] = (dig >> 2) & 1;
      g[i][j | 2] = (dig >> 1) & 1;
      g[i][j | 3] = dig & 1;
    }
  }
  vector<int> ind(n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (g[i][j])
        ++ind[j];
  ll ans = 0;
  queue<int> q;
  for (int i = 0; i < n; ++i) if (!ind[i]) q.push(i);
  int m = n;
  while (!q.empty()) {
    int i = q.front(); q.pop();
    ans += (--m) * (C * (ll)n + 1);
    for (int j = 0; j < n; ++j)
      if (g[i][j] && !--ind[j]) q.push(j);
  }
  if (m == 0) {
    cout << ans << '\n';
    return 0;
  }
  int x = 0;
  for (int i = 1; i < n; ++i) if (ind[x] < ind[i]) x = i;
  vector<int> pb, qb;
  for (int i = 0; i < n; ++i)
    if (ind[i]) {
      if (i == x || g[i][x])
        pb.push_back(i);
      else
        qb.push_back(i);
    }
  ans += 3 * pb.size() * qb.size();
  vector<int> alt(n);
  for (int i : pb) {
    for (int j : qb)
      if (g[i][j])
        ++alt[j];
      else
        ++alt[i];
  }
  for (int i : pb)
    for (int j : pb)
      if (i != j) {
        if (g[i][j])
          ++ans;
        else if (alt[i] == alt[j])
          ans += 3;
        else ans += 2;
      }
  for (int i : qb)
    for (int j : qb)
      if (i != j) {
        if (g[i][j])
          ++ans;
        else if (alt[i] == alt[j])
          ans += 3;
        else ans += 2;
      }
  cout << ans << '\n';

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}