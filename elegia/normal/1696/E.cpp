#include <cmath>
#include <cstring>

#include <algorithm>
#include <stack>
#include <bitset>
#include <numeric>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

using ull = unsigned long long;
using ll = long long;

const int P = 1000000007;

int norm(int x) {
  return x >= P ? x - P : x;
}
void add(int& a, int b) {
  if ((a += b) >= P) {
    a -= P;
  }
}
void sub(int& a, int b) {
  if ((a -= b) < 0) {
    a += P;
  }
}
void fam(int& a, int b, int c) {
  a = (a + b * (ull)c) % P;
}
int mpow(int a, int k) {
  if (k == 0) {
    return 1;
  }
  int ret = mpow(a * (ull)a % P, k >> 1);
  if (k & 1) {
    ret = ret * (ull)a % P;
  }
  return ret;
}

const int _ = 400005;

int fac[_], ifac[_];

void pre(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * (ull)i % P;
  ifac[n] = mpow(fac[n], P - 2);
  for (int i = n; i; --i) ifac[i - 1] = ifac[i] * (ull)i % P;
}

int binom(int n, int m) { return fac[n] * (ull)ifac[m] % P * ifac[n - m] % P; }

int a[_], b[_];

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  
  pre(_ - 1);
  int n, ans = P - 1; cin >> n;
  for (int i = 0; i <= n; ++i) {
    cin >> a[i];
    if (a[i]) {
      add(ans, binom(i + a[i] - 1, i));
      ++b[a[i]];
    }
  }
  if (a[0] == 0) {
    cout << "0\n";
    return 0;
  }
  for (int i = 2e5; i >= 1; --i) {
    b[i] += b[i + 1];
    if (b[i]) {
      add(ans, binom(i + b[i] - 2, i - 1));
    }
  }
  cout << ans << '\n';

  return 0;
}