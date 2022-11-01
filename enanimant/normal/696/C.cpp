// April 17, 2020
// https://codeforces.com/problemset/problem/696/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


const long long MOD = 1e9 + 7;
const long long INV2 = (MOD + 1) / 2;
const long long INV3 = (MOD + 1) / 3;

long long power(long long b, long long e) {
  long long res = 1;
  while (e > 0) {
    if (e & 1) {
      res = res * b % MOD;
    }
    b = b * b % MOD;
    e >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int k;
  cin >> k;
  long long p = 2;
  bool odd = true;
  while (k--) {
    long long a;
    cin >> a;
    p = power(p, a);
    odd &= (a % 2 == 1);
  }
  p = p * INV2 % MOD;
  long long num = p + (odd ? -1 : 1);
  num = (num % MOD + MOD) % MOD;
  num = num * INV3 % MOD;
  long long den = p;
  cout << num << '/' << den << '\n';


  return 0;
}