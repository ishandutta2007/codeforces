// July 24, 2019
// https://codeforces.com/contest/1196/problem/D1
// https://codeforces.com/contest/1196/problem/D2

/*
Same code for both subtasks.
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


  int q;
  cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    vector<int> s(n);
    vector<int> ch(3, 0);
    int ans = n;
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      s[i] = (c == 'R' ? 0 : c == 'G' ? 1 : 2);
      for (int j = 0; j < 3; j++) {
        int e = (i + j) % 3;
        if (s[i] != e) {
          ch[j]++;
        }
        if (i >= k) {
          int e = (i - k + j) % 3;
          if (s[i - k] != e) {
            ch[j]--;
          }
        }
        if (i >= k - 1) {
          ans = min(ans, ch[j]);
        }
      }
    }
    cout << ans << '\n';
  }


  return 0;
}