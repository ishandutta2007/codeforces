// August 25, 2019
// https://codeforces.com/contest/1208/problem/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int N = 1000;


int a[N][N];
int b[4][4] = {{8, 9, 1, 13}, {3, 12, 7, 5}, {0, 2, 4, 11}, {6, 10, 15, 14}};

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
  for (int i = 0; i < n / 4; i++) {
    for (int j = 0; j < n / 4; j++) {
      int add = 16 * (n / 4 * i + j);
      for (int ii = 0; ii < 4; ii++) {
        for (int jj = 0; jj < 4; jj++) {
          a[4 * i + ii][4 * j + jj] = b[ii][jj] + add;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << (j < n - 1 ? ' ' : '\n');
    }
  }
  // int all = -1;
  // for (int i = 0; i < n; i++) {
  //   int x1 = 0, x2 = 0;
  //   for (int j = 0; j < n; j++) {
  //     x1 ^= a[i][j];
  //     x2 ^= a[j][i];
  //   }
  //   if (all == -1) {
  //     all = x1;
  //   }
  //   // assert(x1 == all && x2 == all);
  //   cout << x1 << '\n';
  //   cout << x2 << '\n';
  // }


  return 0;
}