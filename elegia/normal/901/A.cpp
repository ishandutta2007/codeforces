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

  int k;
  cin >> k;
  vector<int> a(k + 1);
  cin >> a;

  vector<int> ans, ano;

  int cur = 0;
  for (int i = 0; i <= k; ++i) {
    for (int j = 0; j < a[i]; ++j)
      ans.push_back(cur);
    cur += a[i];
  }

  for (int i = 0; i < k; ++i) {
    if (a[i] > 1 && a[i + 1] > 1) {
      cout << "ambiguous\n";
      cur = 0;
      for (int j = 0; j <= i; ++j) {
        for (int t = 0; t < a[j]; ++t)
          ano.push_back(cur);
        cur += a[j];
      }
      ano.push_back(cur - 1);
      for (int t = 1; t < a[i + 1]; ++t)
        ano.push_back(cur);
      cur += a[i + 1];
      for (int j = i + 2; j <= k; ++j) {
        for (int t = 0; t < a[j]; ++t)
          ano.push_back(cur);
        cur += a[j];
      }

      cout << ans << '\n' << ano << '\n';
      return 0;
    }
  }
  cout << "perfect" << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}