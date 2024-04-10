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

const int N = 300010;

int n, k, ans;
char s[N + 1];
int f[N * 2], cost[N * 2];

vector<int> a[N];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void merge(int x, int y) {
  x = find(x); y = find(y);
  if (x == y) return;
  int dualX = find(x ^ 1), dualY = find(y ^ 1);
  ans -= min(cost[x], cost[dualX]) + min(cost[y], cost[dualY]);
  cost[x] += cost[y];
  f[y] = x;
  cost[dualX] += cost[dualY];
  f[dualY] = dualX;
  ans += min(cost[x], cost[dualX]);
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k >> (s + 1);
  for (int i = 1; i <= k; ++i) {
    int c;
    cin >> c;
    while (c--) {
      int x;
      cin >> x;
      a[x].push_back(i);
    }
  }
  ++k;
  for (int i = 1; i <= n; ++i)
    if (a[i].size() == 1)
      a[i].push_back(k);
  for (int i = 1; i < k; ++i) cost[i * 2 - 2] = 1;
  cost[k * 2 - 2] = 1e9;
  iota(f, f + k * 2, 0);
  for (int i = 1; i <= n; ++i) {
    if (a[i].empty()) {
      cout << ans << '\n';
      continue;
    }
    if (s[i] == '1')
      merge(a[i][0] * 2 - 2, a[i][1] * 2 - 2);
    else
      merge(a[i][0] * 2 - 2, a[i][1] * 2 - 1);
    cout << ans << '\n';
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}