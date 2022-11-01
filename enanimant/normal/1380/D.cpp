// July 12, 2020
// https://codeforces.com/contest/1380/problem/D

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
  
  
  int n, m;
  cin >> n >> m;
  int x, k, y;
  cin >> x >> k >> y;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    b[i]--;
  }
  int last = -1;
  int p = 0;
  bool ok = true;
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    if (i == n || (p < m && a[i] == b[p])) {
      int l = last + 1, r = i - 1;
      int sz = r - l + 1;
      if (sz > 0) {
        int mx = -1;
        for (int j = l; j <= r; j++) {
          mx = max(mx, a[j]);
        }
        // can kill this interval using berserks
        bool b = ((last >= 0 && a[last] > mx) || (i < n && a[i] > mx));
        if (!b && sz < k) {
          ok = false;
        }
        long long cost = 1e18;
        if (sz >= k) {
          int t = sz - k;
          int kill_k = min(1LL * x, 1LL * k * y);
          cost = min(cost, x + 1LL * t / k * kill_k + 1LL * (t % k) * y);
        }
        if (b) {
          cost = min(cost, 1LL * sz * y);
        }
        ans += cost;
      }

      // int kill_k = min(1LL * x, 1LL * k * y);
      // ans += 1LL * sz / k * kill_k + 1LL * (sz % k) * y;
      // 
      // if (sz < k) {
      //   int mx = -1;
      //   for (int j = l; j <= r; j++) {
      //     mx = max(mx, a[j]);
      //   }
      //   if ((last >= 0 && a[last] > mx) || (i < n && a[i] > mx)) {
      //     ans += 1LL * sz * y;
      //   } else {
      //     ok = false;
      //     break;
      //   }
      // } else {
      //   int kill_k = min(1LL * x, 1LL * k * y);
      //   ans += 1LL * sz / k * kill_k + 1LL * (sz % k) * y;
      // }
      if (i < n) {
        last = i;
        p++;
      }
    }
  }
  ok &= (p == m);
  cout << (ok ? ans : -1) << '\n';
  
  
  return 0;
}