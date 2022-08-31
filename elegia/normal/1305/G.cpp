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

const int N = (1 << 18) + 5;

int n;
ll ans;
int f[N], c[N];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  int m = 0;
  while (n--) {
    int a;
    cin >> a;
    m = max(m, a);
    ans -= a;
    ++c[a];
  }
  int l = 0;
  while ((1 << l) <= m) ++l;
  iota(f, f + (1 << l), 0);
  ++c[0];
  for (int i = (1 << l) - 1; i >= 0; --i) {
    for (int j = i; ; j = (j - 1) & i) {
      if (c[j] && c[i ^ j]) {
        int x = find(j), y = find(i ^ j);
        if (x != y) {
          f[x] = y;
          ans += i * (c[j] + c[i ^ j] - 1LL);
          c[j] = c[i ^ j] = 1;
        }
      }

      if (j == 0) break;
    }
  }
  cout << ans << '\n';

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}