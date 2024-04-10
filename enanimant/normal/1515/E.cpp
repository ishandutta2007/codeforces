/*
 * author:  ADMathNoob
 * created: 05/02/21 10:34:14
 * problem: https://codeforces.com/contest/1515/problem/E
 */

/*
g++ 1515E.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 1515E.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wfatal-errors -O3


*/

#include <bits/stdc++.h>

using namespace std;

int md;

void add(int& a, const int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

int mul(const int a, const int b) {
  return (int) ((long long) a * b % md);
}

int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

int inv(int a) {
  return power(a, md - 2);
}

const int N = 405;

int choose[N][N];
int fact[N];
int inv_fact[N];

int ways_by_side[N][N];
int ways[N];
int dp[N][N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n >> md;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0) {
        choose[i][j] = 1;
      } else {
        choose[i][j] = choose[i - 1][j];
        add(choose[i][j], choose[i - 1][j - 1]);
      }
    }
  }
  fact[0] = 1;
  inv_fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
    inv_fact[i] = mul(inv_fact[i - 1], inv(i));
    // cerr << inv_fact[i] << '\n';
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == 0 || j == 0) {
        ways_by_side[i][j] = 1;
      } else {
        ways_by_side[i][j] = ways_by_side[i - 1][j];
        add(ways_by_side[i][j], ways_by_side[i][j - 1]);
      }
      // cerr << i << ' ' << j << ' ' << ways_by_side[i][j] << '\n';
    }
  }
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < i; j++) {
      add(ways[i], ways_by_side[j][i - 1 - j]);
    }
    // cerr << "ways to fill " << i << ": " << ways[i] << '\n';
  }
  
  dp[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (i > 2) {
        // last alone
        add(dp[i][j], dp[i - 2][j - 1]);
      }
      for (int s = 2; s <= j; s++) {
        if (s <= i - 2) {
          add(dp[i][j], mul(dp[i - s - 1][j - s], mul(ways[s], inv_fact[s])));
        }
      }
    }
    add(dp[i][i], mul(ways[i], inv_fact[i]));
  }
  // cerr << dp[3][3] << '\n';
  int ans = 0;
  for (int m = 1; m <= n; m++) {
    // cerr << dp[n][m] << '\n';
    // cerr << "m = " << m << ": " << dp[n][m] * fact[m] << '\n';
    add(ans, mul(dp[n][m], fact[m]));
  }
  cout << ans << '\n';
  return 0;
}