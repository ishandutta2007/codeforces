// March 23, 2020
// https://codeforces.com/contest/1327/problem/E

/*

*/


#include <bits/stdc++.h>

using namespace std;


constexpr int MOD = 998244353;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int n;
  cin >> n;
  vector<long long> pow10(n + 1);
  pow10[0] = 1;
  for (int i = 1; i <= n; i++) {
    pow10[i] = pow10[i - 1] * 10 % MOD;
  }
  long long d = 0;
  for (int i = 1; i <= n; i++) {
    if (i > 1) {
      cout << ' ';
    }
    long long res = (i == n ? 1 : 2 * 9 * pow10[n - i - 1] + (n - i - 1) * 81 * pow10[n - i - 2]);
    res = res * 10 % MOD;
    cout << res;
    d += res * i;
  }
  cout << '\n';
  cerr << d << '\n';


  return 0;
}