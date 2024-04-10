// August 23, 2019
// https://codeforces.com/contest/1191/problem/C

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


  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> p(m);
  for (int i = 0; i < m; i++) {
    cin >> p[i];
    p[i]--;
  }
  if (k == n) {
    cout << "1\n";
    return 0;
  }
  int cnt = 0;
  int ans = 0;
  while (cnt < m) {
    long long pos = (p[cnt] - cnt) % k;
    long long rem = k - 1 - pos;
    int first = cnt;
    while (cnt < m && p[cnt] - p[first] <= rem) {
      cnt++;
    }
    ans++;
  }
  cout << ans << '\n';


  return 0;
}