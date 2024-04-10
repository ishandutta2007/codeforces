#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int mod = 1000000007;
int fact[100005];
int rfact[100005];
vector<pair<int, int> > v;

int mPow(int a, int x) {
  int ret = 1;
  while (x > 0) {
    if (x & 1) {
      ret = 1LL * ret * a % mod;
    }
    a = 1LL * a * a % mod;
    x >>= 1;
  }
  return ret;
}

int C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return 1LL * fact[n] * rfact[k] % mod * rfact[n - k] % mod;
}

int n;

int solve(int l, int r) {
  // cout << l << "  " << r << endl;
  if (l < 1 || r > n) return 0;
  int ans = 1;
  for (int i = 1; i < v.size(); ++i) {
    int add;
    if (v[i].second >= l && v[i].second <= r || l < 1 || r > n) {
      return 0;
    }
    if (v[i].second < l) add = l - v[i].second - 1;
    else add = v[i].second - r - 1;
    ans = 1LL * ans * C(v[i].first - v[i - 1].first - 1, add) % mod;
    int other = v[i].first - v[i - 1].first - 1 - add;
    if (other < 0) return 0;
    if (v[i].second < l) {
      l -= add + 1;
      r += other;
    } else {
      r += add + 1;
      l -= other;
    }
    // cout << v[i].second << endl;
    // cout << other << "  " << add << endl;
    // cout << l << "  " << r << " " << ans << endl;
  }
  int tot = (l - 1) + (n - r);
  return 1LL * ans * C(tot, l - 1) % mod;
}

int main() {
  fact[0] = rfact[0] = 1;
  for (int i = 1; i <= 100000; ++i) {
    fact[i] = 1LL * fact[i - 1] * i % mod;
    rfact[i] = mPow(fact[i], mod - 2);
  }

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (a != 0)
     v.push_back(make_pair(a - 1, i + 1));
  }
  sort(v.begin(), v.end());
  if (v.size() == 0) {
    printf("%d\n", mPow(2, n - 1));
    return 0;
  }
  // cout << mPow(2, v[0].first - 1) << endl;
  int ans = 1LL * mPow(2, v[0].first - 1) * 
    (solve(v[0].second, v[0].second + v[0].first) + (v[0].first != 0 ? solve(v[0].second - v[0].first, v[0].second) : 0)) % mod;
  printf("%d\n", ans);
  return 0;
}