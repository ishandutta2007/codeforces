// June 4, 2020
// https://codeforces.com/contest/1361/problem/B

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int MOD = 1e9 + 7;

int power(int b, int e) {
  int res = 1;
  while (e > 0) {
    if (e & 1) {
      res = (long long) res * b % MOD;
    }
    b = (long long) b * b % MOD;
    e >>= 1;
  }
  return res;
}

bool Less(int p, long long m, int e, int rem, int mx) {
  // m * p^e > rem * p^mx
  if (m == 0) {
    return false;
  }
  if (p == 1) {
    return (m > rem);
  }
  e -= mx;
  long long x = m;
  for (int i = 0; i <= e; i++) {
    if (x > rem) {
      return true;
    }
    x *= p;
    // cerr << "looped; m = " << m << ", ";
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
  
  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    long long m = 1;
    int e = a[0];
    for (int i = 1; i <= n; i++) {
      if (i == n || Less(p, m, e, n - i, a[i])) {
        m %= MOD;
        long long ans = m * power(p, e) % MOD;
        for (int j = i; j < n; j++) {
          ans -= power(p, a[j]);
          if (ans < 0) {
            ans += MOD;
          }
        }
        cout << ans << '\n';
        break;
      }
      m *= power(p, e - a[i]);
      e = a[i];
      if (m == 0) {
        m++;
      } else {
        m--;
      }
    }
  }
  
  
  return 0;
}