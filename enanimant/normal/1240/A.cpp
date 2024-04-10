// October 6, 2019
// http://codeforces.com/contest/1240/problem/A

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      p[i] /= 100;
    }
    long long x, a, y, b, k;
    cin >> x >> a >> y >> b >> k;
    if (x < y) {
      swap(a, b);
      swap(x, y);
    }
    sort(p.rbegin(), p.rend());
    int lo = 1, hi = n + 1;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      long long tot = 0;
      int c = 0;
      long long lcm = a * b / __gcd(a, b);
      for (long long i = lcm; i <= mid; i += lcm) {
        tot += (x + y) * p[c++];
      }
      for (int i = a; i <= mid; i += a) {
        if (i % b != 0) {
          tot += x * p[c++];
        }
      }
      for (int i = b; i <= mid; i += b) {
        if (i % a != 0) {
          tot += y * p[c++];
        }
      }
      if (tot >= k) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    cout << (lo <= n ? lo : -1) << '\n';
  }


  return 0;
}