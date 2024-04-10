// September 14, 2019
//

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


  int n;
  cin >> n;
  vector<int> on(n);
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    on[i] = c - '0';
  }
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  int ans = 0;
  for (int t = 0; t < 200; t++) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (t >= b[i] && (t - b[i]) % a[i] == 0) {
        on[i] ^= 1;
      }
      cnt += on[i];
    }
    ans = max(ans, cnt);
  }
  cout << ans << '\n';


  return 0;
}