/*
 * author:  ADMathNoob
 * created: 08/29/21 10:35:22
 * problem: https://codeforces.com/contest/1556/problem/D
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

int And(int i, int j) {
  cout << "and " << i << ' ' << j << endl;
  int r;
  cin >> r;
  return r;
}

int Or(int i, int j) {
  cout << "or " << i << ' ' << j << endl;
  int r;
  cin >> r;
  return r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  long long and12 = And(1, 2);
  long long and13 = And(1, 3);
  long long and23 = And(2, 3);
  long long or12 = Or(1, 2);
  long long or13 = Or(1, 3);
  long long or23 = (and12 ^ or12 ^ and13 ^ or13 ^ and23);
  long long sum = (and12 + or12 + and13 + or13 + and23 + or23) / 2;
  vector<long long> ans(n + 1, 0);
  ans[1] = sum - (and23 + or23);
  ans[2] = sum - (and13 + or13);
  ans[3] = sum - (and12 + or12);
  for (int i = 4; i <= n; i++) {
    ans[i] = (And(1, i) ^ Or(1, i) ^ ans[1]);
  }
  sort(ans.begin() + 1, ans.begin() + n + 1);
  cout << "finish " << ans[k] << endl;
  return 0;
}