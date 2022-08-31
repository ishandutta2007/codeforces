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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n); cin >> a;
    int A = *max_element(a.begin(), a.end());
    vector<vector<int>> ind(A, vector<int>(1, -1));
    for (int i = 0; i < n; ++i) ind[--a[i]].push_back(i);
    for (int i = 0; i < A; ++i) ind[i].push_back(n);
    int ans = 0;
    for (int i = 0; i < A; ++i) {
      int cur = 0;
      vector<int> cnt(A);
      int x = ind[i].size() / 2 - 1;
      for (int j = ind[i][x] + 1; j < ind[i][ind[i].size() - 1 - x]; ++j)
        cur = max(cur, ++cnt[a[j]]);
      ans = max(ans, cur + x * 2);
      for (int j = x; j; --j) {
        for (int k = ind[i][j - 1] + 1; k <= ind[i][j]; ++k)
          cur = max(cur, ++cnt[a[k]]);
        for (int k = ind[i][ind[i].size() - 1 - j]; k < ind[i][ind[i].size() - j]; ++k)
          cur = max(cur, ++cnt[a[k]]);
        ans = max(ans, cur + (j - 1) * 2);
      }
    }
    cout << ans << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}