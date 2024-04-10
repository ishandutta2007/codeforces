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

  auto solve = [&](const vector<int> a, int k) {
    int n = a.size();
    int cnt = count(a.begin(), a.end(), k);
    if (cnt == n) return true;
    if (cnt == 0) return false;
    vector<int> ind;
    for (int i = 0; i < n; ++i) if (a[i] >= k) ind.push_back(i);
    for (int i = 1; i < ind.size(); ++i) if (ind[i] - ind[i - 1] <= 2) return true;
    return false;
  };

  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;

    cout << (solve(a, k) ? "yes\n" : "no\n");
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}