#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

const int md = 1e9 + 7;

int mul(int a, int b) {
  return ((ll)a * b) % md;
}

int power(int a, ll b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

int inv(int a) {
  return power(a, md - 2);
}

const int N = 1e6 + 7;

int f[N];
int rf[N];

int C(int n, int k) {
  return mul(f[n], mul(rf[n - k], rf[k]));
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  f[0] = 1;
  for (int i = 1; i < N; ++i) f[i] = mul(f[i - 1], i);
  for (int i = 0; i < N; ++i) rf[i] = inv(f[i]);
  int n;
  cin >> n;
  int ans = f[n];
  for (int pos = 0; pos < n; ++pos) {
    int bad = C(n - 1, pos);
    ans -= bad;
    if (ans < 0) ans += md;
  }
  cout << ans << '\n';
}