// August 22, 2019
// https://codeforces.com/contest/1207/problem/F

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int N = 500000;
const int B = 800;


int a[N + 1];
int sum[B][B]; // sum[i][j]: a[j] + a[j + i] + a[j + 2 * i] + ...

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
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      a[x] += y;
      for (int i = 1; i < B; i++) {
        sum[i][x % i] += y;
      }
    } else {
      int ans = 0;
      if (x < B) {
        ans = sum[x][y];
      } else {
        for (int i = y; i <= N; i += x) {
          ans += a[i];
        }
      }
      cout << ans << '\n';
    }
  }


  return 0;
}