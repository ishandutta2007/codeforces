// March 19, 2020
// https://codeforces.com/contest/1325/problem/C

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


  int n, k;
  cin >> n >> k;
  vector<int> p(n), pos(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
    pos[p[i]] = i;
  }
  vector<int> v;
  long long val = 0;
  for (int i = n - k; i < n; i++) {
    v.push_back(pos[i]);
    val += i + 1;
  }
  sort(v.begin(), v.end());
  long long ans = 1;
  for (int i = 0; i < k - 1; i++) {
    ans *= v[i + 1] - v[i];
    ans %= MOD;
  }
  cout << val << ' ' << ans << '\n';


  return 0;
}