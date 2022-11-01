// December 30, 2020
// https://codeforces.com/contest/1466/problem/E

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1466E.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1466E.cpp -ggdb && gdb a
*/


#include <bits/stdc++.h>

using namespace std;


const int MOD = (int) 1e9 + 7;
const int BITS = 60;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  vector<long long> pow2(BITS + 1, 1);
  for (int i = 0; i < BITS; i++) {
    pow2[i + 1] = pow2[i] * 2 % MOD;
  }

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> cnt(BITS, 0);
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      for (int j = 0; j < BITS; j++) {
        if (a[i] & (1LL << j)) {
          cnt[j] += 1;
        }
      }
      sum = (sum + a[i]) % MOD;
    }
    long long ans = 0;
    for (int j = 0; j < n; j++) {
      long long andd = 0;
      for (int b = 0; b < BITS; b++) {
        if (a[j] & (1LL << b)) {
          andd += pow2[b] * cnt[b] % MOD;
          andd %= MOD;
        }
      }
      long long orr = ((a[j] % MOD) * n + sum - andd) % MOD;
      if (orr < 0) {
        orr += MOD;
      }
      ans += andd * orr % MOD;
      ans %= MOD;
    }
    cout << ans << '\n';
  }


  return 0;
}