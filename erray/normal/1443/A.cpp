// author: erray
#include<bits/stdc++.h>
 
using namespace std;

namespace sieve {
  vector<int> list(int n) {
    assert(n <= (int) 3e8 && n >= 0);
    if (n == 0) return vector<int>(0);
    vector<int> res;
    vector<bool> ip(n + 1, true);
    for (int i = 2; i <= n; ++i) {
      if (!ip[i]) continue;
      res.push_back(i);
      if ((int) ceil(1.0 * n / i) < i) continue;
      for (int j = i * i; j <= n; j += i) {
        ip[j] = false;
      }
    }
    return res;
  }

  vector<bool> check(int n) {
    assert(n <= (int) 3e8 && n >= 0);
    if (n == 0) return vector<bool>(1, false);
    vector<bool> ip(n + 1, true);
    for (int i = 2; i <= n; ++i) {
      if (!ip[i]) continue;
      if (ceil(1.0 * n / i) < i) continue;
      for (int j = i * i; j <= n; j += i) {
        ip[j] = false;
      }
    }
    ip[0] = false;
    if (n > 1) ip[1] = false;
    return ip;
  }
}
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> ans;
    for (int i = n * 4; i >= 2; --i) {
      bool ok = true;
      for (auto el : ans) {
        ok &= (el % i) != 0 && gcd(i, el) != 1;
      }
      if (ok) {
        ans.push_back(i);
      }
    }
    assert((int) ans.size() >= n);
    for (int i = 0; i < n; ++i) {
      cout << ans[i] << " \n"[i == n - 1];
    }
  }
}