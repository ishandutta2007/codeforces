// July 11, 2019
// https://codeforces.com/contest/1189/problem/E

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


  int n, p, k;
  cin >> n >> p >> k;
  map<int, int> m;
  while (n--) {
    long long a;
    cin >> a;
    long long a2 = a * a % p;
    long long a4 = a2 * a2 % p;
    m[((a4 - a * k) % p + p) % p]++;
  }
  long long ans = 0;
  for (auto pp : m) {
    ans += (long long) pp.second * (pp.second - 1) / 2;
  }
  cout << ans << '\n';


  return 0;
}