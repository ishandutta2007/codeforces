// August 7, 2019
// https://codeforces.com/contest/1202/problem/D

/*

*/


#include <bits/stdc++.h>

using namespace std;


int f(int x) {
  long long lo = 0, hi = 1e7;
  while (lo < hi) {
    long long mid = (lo + hi) / 2;
    if (mid * mid - mid - 2 * x <= 0) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return lo - 1;
}

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
    vector<int> a;
    while (n > 0) {
      int b = f(n);
      a.push_back(b);
      n -= b * (b - 1) / 2;
    }
    reverse(a.begin(), a.end());
    cout << 1;
    for (int i = 0; i < a.size(); i++) {
      int cnt3 = a[i];
      if (i > 0) {
        cnt3 -= a[i - 1];
      }
      while (cnt3--) {
        cout << 3;
      }
      cout << 7;
    }
    cout << '\n';
  }


  return 0;
}