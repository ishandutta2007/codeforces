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
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;

const int md = 998244353;

void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}

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

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector <int> d(n);
  for (int i = 0; i < n; ++i) cin >> d[i];
  sort(d.rbegin(), d.rend());
  vector <int> a(m), b(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i] >> b[i];
  }
  vector <int> p(m);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&] (int i, int j) {
    return b[i] > b[j];
  });
  vector <int> res(m);
  int sum_good = 0, sum_bad = 0;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    add(sum_bad, d[i] % md);
  }
  int uk = 0;
  for (int i = 0; i < m; ++i) {
    while (uk < n && b[p[i]] <= d[uk]) {
      ++cnt;
      add(sum_good, d[uk] % md);
      sub(sum_bad, d[uk] % md);
      ++uk;
    }
    int ans = 0;
    if (a[p[i]] <= cnt) add(ans, mul(sum_bad, mul((cnt + 1 - a[p[i]]), inv(cnt + 1))));
    if (a[p[i]] < cnt) add(ans, mul(sum_good, mul(cnt - a[p[i]], inv(cnt))));
    res[p[i]] = ans;
    /*int cnt = 0;
    for (int j = 0; j < n; ++j) {
      if (b[i] <= d[j]) {
        ++cnt;
      }
    }
    int ans = 0;
    if (a[i] <= cnt) {
      for (int j = 0; j < n; ++j) {
        if (b[i] <= d[j]) {
          if (a[i] < cnt) add(ans, mul(d[j], mul(cnt - a[i], inv(cnt))));
        } else {
          add(ans, mul(d[j], mul((cnt + 1 - a[i]), inv(cnt + 1))));
        }
      }
    }
    cout << ans << '\n';*/
  }
  for (int i = 0; i < m; ++i) {
    cout << res[i] << '\n';
  }
}