/*
 * author:  ADMathNoob
 * created: 08/29/21 10:35:12
 * problem: https://codeforces.com/contest/1556/problem/B
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ones;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] %= 2;
      if (a[i] == 1) {
        ones.push_back(i);
      }
    }
    auto Calc = [&](const vector<int>& b) {
      assert(ones.size() == b.size() && is_sorted(b.begin(), b.end()));
      long long res = 0;
      for (int i = 0; i < (int) ones.size(); i++) {
        res += abs(ones[i] - b[i]);
      }
      return res;
    };
    int sum = (int) ones.size();
    const long long INF = 1e18;
    long long best = INF;
    if (n % 2 == 0) {
      if (sum == n / 2) {
        for (int add = 0; add < 2; add++) {
          vector<int> b(sum);
          for (int i = 0; i < n / 2; i++) {
            b[i] = 2 * i + add;
          }
          best = min(best, Calc(b));
        }
      }
    } else {
      if (sum == (n - 1) / 2) {
        vector<int> b(sum);
        for (int i = 0; i < sum; i++) {
          b[i] = 2 * i + 1;
        }
        best = Calc(b);
      }
      if (sum == (n + 1) / 2) {
        vector<int> b(sum);
        for (int i = 0; i < sum; i++) {
          b[i] = 2 * i;
        }
        best = Calc(b);
      }
    }
    cout << (best < INF ? best : -1) << '\n';
  }
  return 0;
}