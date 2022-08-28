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
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    auto solve1 = [&](int n, int k) {
      if (n % 2 != k % 2 || n < k)
        return false;
      n -= k - 1;
      while (--k) ans.push_back(1);
      ans.push_back(n);
      return true;
    };
    auto solve0 = [&](int n, int k) {
      if (n % 2 == 1 || n < k * 2)
        return false;
      n -= (k - 1) * 2;
      while (--k) ans.push_back(2);
      ans.push_back(n);
      return true;
    };
    if (solve0(n, k))
      cout << "YES\n" << ans << '\n';
    else if (solve1(n, k))
      cout << "YES\n" << ans << '\n';
    else
      cout << "NO\n";
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}