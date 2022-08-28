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

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i != n; ++i) cin >> a[i];
    long long x = 0;
    bool ans = true, fafa = false;
    for (int i = n - 1; i >= 0; --i) {
      x += a[i];
      // cerr << x << ' ';
      if (x) fafa = true;
      if (x == 0 && fafa && i > 0) ans = false;
      if (x > 0) ans = false;
    }
    // cerr << '\n';
    if (x != 0) ans = false;
    cout << (ans ? "YES" : "NO") << endl;
  }

  return 0;
}