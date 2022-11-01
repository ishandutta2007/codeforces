// July 14, 2019
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


  int q;
  cin >> q;
  while (q--) {
    int n, m;
    cin >> n >> m;
    vector< vector<int> > a(n, vector<int>(m));
    vector<int> rcnt(n, 0), ccnt(m, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char c;
        cin >> c;
        a[i][j] = (c == '*' ? 0 : 1);
        rcnt[i] += a[i][j];
        ccnt[j] += a[i][j];
      }
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int white = rcnt[i] + ccnt[j];
        if (a[i][j] == 1) {
          white--;
        }
        ans = min(ans, white);
      }
    }
    cout << ans << '\n';
  }


  return 0;
}