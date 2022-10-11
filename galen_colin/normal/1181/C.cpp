#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
int i, j, k;
typedef long long ll;

int n, m;
int grid[1001][1001];
ll pre[26][1001][1001];

int q(int br, int tr, int bc, int tc, int k) {
  if (br == 0 && bc == 0) return pre[k][tr][tc];
  if (br == 0) return pre[k][tr][tc] - pre[k][tr][bc - 1];
  if (bc == 0) return pre[k][tr][tc] - pre[k][br - 1][tc];
  return pre[k][tr][tc] - pre[k][br - 1][tc] - pre[k][tr][bc - 1] + pre[k][br - 1][bc - 1];
}

/* find place to go down */
int bs1(int r, int c, int l, int h) {
  if (l > h) return h;

  int m = (l + h) / 2;

  /* full */
  if (q(r, r + m, c, c, grid[r][c]) == m + 1) 
    return bs1(r, c, m + 1, h);
  else  
    return bs1(r, c, l, m - 1);
}

int bs2(int r, int c, int l, int h, int down) {
  if (l > h) return h;

  int m = (l + h) / 2;

  bool cond1 = (q(r, r + down, c, c + m, grid[r][c]) == (m + 1) * (down + 1)),
  cond2 = (q(r + down + 1, r + 2 * down + 1, c, c + m, grid[r+down+1][c]) == (m + 1) * (down + 1)),
  cond3 = (q(r + 2 * down + 2, r + 3 * down + 2, c, c + m, grid[r+2*down+2][c]) == (m + 1) * (down + 1));
  // cout << l << " " << h << " " << cond1 << cond2 << cond3 << endl;
  
  if (cond1 && cond2 && cond3 && grid[r][c] != grid[r+down+1][c] && grid[r+down+1][c] != grid[r+2*down+2][c]) 
    return bs2(r, c, m + 1, h, down);
  else  
    return bs2(r, c, l, m - 1, down);
}

int main() {
  io;
  cin >> n >> m;
  f0r(i, n) {
    f0r(j, m) {
      char c;
      cin >> c;
      grid[i][j] = c - 'a';
    }
  }

  f0r(k, 26) {
    f0r(i, n) {
      pre[k][i][0] = (grid[i][0] == k);
      f1r(j, 1, m) {
        pre[k][i][j] = pre[k][i][j - 1] + (grid[i][j] == k);
      }
    }
  }

  f0r(k, 26) {
    f1r(i, 1, n) {
      f0r(j, m) {
        pre[k][i][j] += pre[k][i - 1][j];
      }
    }
  }

  // f0r(k, 4) {
  //   f0r(i, n) {
  //     f0r(j, m) {
  //       cout << pre[k][i][j] << " ";
  //     }
  //     cout << endl;
  //   }
  //   cout << endl << endl;
  // }

  ll ans = 0;
  f0r(i, n - 2) {
    int pt = 0;
    while (pt < m) {
      int a = bs1(i, pt, 0, n - i - 1);
      if (i + 3*a + 2 >= n) {
        pt++;
        continue;
      }
      int b = bs2(i, pt, 0, m - pt - 1, a);
      // cout << i << " " << pt << " " << a << " " << b << endl;
      if (a < 0 || b < 0) {
        pt++;
      } else {
        ans += (b + 1) * (b + 2) / 2;
        pt += b + 1;
      }
    }
  }

  cout << ans << endl;
}