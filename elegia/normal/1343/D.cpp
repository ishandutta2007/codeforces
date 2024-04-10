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

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<int> a(n); cin >> a;
    vector<int> cost(k * 2);
    for (int& x : a) --x;
    for (int i = 0; i < n / 2; ++i) {
      int cnt = 0;
      if (a[i] >= k) ++cnt;
      if (a[n - i - 1] >= k) ++cnt;
      if (cnt == 2)
        cost[0] += 2;
      else if (cnt == 1) {
        cost[0] += 2;
        int x = min(a[i], a[n - i - 1]);
        --cost[x];
        ++cost[x + k];
      } else {
        cost[0] += 2;
        --cost[min(a[i], a[n - i - 1])];
        --cost[a[i] + a[n - i - 1]];
        ++cost[a[i] + a[n - i - 1] + 1];
        ++cost[max(a[i], a[n - i - 1]) + k];
      }
    }
    for (int i = 1; i <= k * 2 - 2; ++i) cost[i] += cost[i - 1];
    cout << *min_element(cost.begin(), cost.begin() + k * 2 - 1) << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}