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

char s[1010];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> (s + 1);
  int n = strlen(s + 1);
  bool f = false, a0 = true;
  for (int i = 1; i <= n; ++i)
    if (s[i] == '(')
      f = true;
    else if (f)
      a0 = false;
  if (a0) {
    cout << "0\n";
    return 0;
  }
  int c0 = 0, c1 = 0;
  for (int i = 1; i <= n; ++i)
    if (s[i] == ')')
      ++c1;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == ')') --c1;
    else ++c0;
    if (c0 == c1) {
      cout << 1 << '\n' << ' ' << (c0 * 2) << '\n';
      for (int j = 1; j <= i; ++j)
        if (s[j] == '(')
          cout << j << ' ';
      for (int j = i + 1; j <= n; ++j)
        if (s[j] == ')')
          cout << j << ' ';
      break;
    }
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}