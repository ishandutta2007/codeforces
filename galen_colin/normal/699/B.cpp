#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j, k;
typedef long long ll;

int n, m, cp[1002], rp[1002];
char grid[1002][1002];

int main() {
  io;
  cin >> n >> m;
  int tot = 0;
  f0r(i, n) f0r(j, m) { cin >> grid[i][j]; if (grid[i][j] == '*') tot++; }
  ms(cp, 0);
  ms(rp, 0);
  f0r(i, n) {
    f0r(j, m) rp[i] += (grid[i][j] == '*');
  }
  f0r(i, m) {
    f0r(j, n) cp[i] += (grid[j][i] == '*');
  }
  bool f = 0;
  f0r(i, n) {f0r(j, m) {
    int p = 0;
    if (grid[i][j] == '*') p--;
    if (p + cp[j] + rp[i] == tot) f = 1;
    if (f) break;
  } if (f) break; }
  if (f) {
    cout << "YES" << endl;
    cout << i + 1 << " " << j + 1 << endl;
  } else cout << "NO" << endl;
}