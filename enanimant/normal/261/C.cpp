// May 12, 2020
// https://codeforces.com/contest/261/problem/C

/*
Sum of row i, where i is 1-indexed, is 2^(b - 1), where
b = __builtin_popcount(i).

How many integers in [0, n] have __builtin_popcount(t) + 1 '1's in binary?
*/


#include <bits/stdc++.h>

using namespace std;


const int B = 50;

long long choose[B][B];

long long solve(long long n, int bits) {
  if (bits == 0) {
    return 1;
  }
  if (n == 0) {
    return (bits == 0);
  }
  int b = 64 - __builtin_clzll(n) - 1;
  cerr << n << ' ' << b << ' ' << bits << '\n';
  long long m = n - (1LL << b);
  return solve(m, bits - 1) + choose[b][bits];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
  
  
  for (int i = 0; i < B; i++) {
    for (int j = 0; j <= i; j++) {
      if (i == 0 || j == 0) {
        choose[i][j] = 1;
        continue;
      }
      choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
    }
  }
  
  long long n, t;
  cin >> n >> t;
  if ((t & (t - 1)) != 0) {
    cout << "0\n";
    return 0;
  }
  n++;
  int bits = __builtin_ctzll(t) + 1;
  
  // first way
  long long ans = solve(n, bits);
  
  // second weird way
  // long long ans = 0;
  // int b = bits;
  // for (int j = B - 1; j >= 0; j--) {
  //   if (n & (1LL << j)) {
  //     if (b >= 0) {
  //       ans += choose[j][b];
  //       b--;
  //     }
  //   }
  // }
  // if (b == 0) {
  //   ans++;
  // }
  
  // m + 1 can never be 1 for positive integers m
  if (bits == 1) {
    ans--;
  }
  cout << ans << '\n';
  
  
  return 0;
}