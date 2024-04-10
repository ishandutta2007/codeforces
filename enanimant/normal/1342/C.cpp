// April 26, 2020
// https://codeforces.com/contest/1342/problem/C

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


  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, q;
    cin >> a >> b >> q;
    vector<int> rems;
    for (int i = 0; i < a * b; i++) {
      if ((i % a) % b != (i % b) % a) {
        rems.push_back(i);
      }
    }
    function<long long(long long)> solve = [&](long long x) {
      // how many in [0, x] satisfy the given?
      int r = x % (a * b);
      long long quo = x / (a * b);
      long long res = quo * rems.size();
      res += upper_bound(rems.begin(), rems.end(), r) - rems.begin() - 1;
      return res;
    };
    for (int i = 0; i < q; i++) {
      if (i > 0) {
        cout << ' ';
      }
      long long l, r;
      cin >> l >> r;
      cout << solve(r) - solve(l - 1);
    }
    cout << '\n';
  }


  return 0;
}