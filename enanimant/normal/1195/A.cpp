// July 28, 2019
// https://codeforces.com/contest/1195/problem/A

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


  int n, k;
  cin >> n >> k;
  vector<int> cnt(k);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cnt[a - 1]++;
  }
  int odd = 0;
  int ans = 0;
  for (int i = 0; i < k; i++) {
    if (cnt[i] % 2 == 1) {
      odd++;
    }
    ans += cnt[i] / 2 * 2;
  }
  ans += (odd + 1) / 2;
  cout << ans << '\n';


  return 0;
}