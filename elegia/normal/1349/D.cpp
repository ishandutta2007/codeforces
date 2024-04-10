#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <cassert>
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

const int P = 998244353;

int norm(int x) { return x >= P ? (x - P) : x; }

void add(int& x, int y) { if ((x += y) >= P) x -= P; }

void sub(int& x, int y) { if ((x -= y) < 0) x += P; }

void exGcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exGcd(b, a % b, y, x);
  y -= a / b * x;
}

int inv(int a) {
  int x, y;
  exGcd(a, P, x, y);
  return norm(x + P);
}


int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  cin >> a;
  int m = accumulate(a.begin(), a.end(), 0);
  vector<int> adex(m);
  int in1 = inv(n - 1), im = inv(m);
  adex[0] = 1;
  for (int i = 1; i < m; ++i) {
    int p = im * (ll)in1 % P * (m - i) % P;
    add(adex[i], p);
    add(adex[i], i * (ll)im % P * adex[i - 1] % P);
    adex[i] = adex[i] * (ll)inv(p) % P;
  }
  vector<int> ex(m + 1);
  for (int i = m - 1; i >= 0; --i)
    ex[i] = norm(ex[i + 1] + adex[i]);
  int ans = 0;
  for (int i = 0; i < n; ++i) add(ans, ex[a[i]]);
  sub(ans, (n - 1LL) % P * (ll)ex[0] % P);
  cout << ans << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}