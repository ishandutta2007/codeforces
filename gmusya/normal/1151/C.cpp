#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef __int128 i128;

const i128 MOD = 1e9 + 7;

int get(i128 n) {
  bool flag = false;
  i128 odd = 0, even = 0;
  i128 p = 1;
  while (odd + even < n) {
    odd += p;
    flag = !flag;
    if (odd + even >= n)
      odd = n - even;
    swap(odd, even);
    p *= 2;
  }
  if (flag)
    swap(odd, even);
  i128 sumodd = odd * odd;
  i128 sumeven = even * (even + 1);
  return (sumodd + sumeven) % MOD + MOD;
}

int main() {
  ll l, r;
  cin >> l >> r;
  cout << (int)(((get(r) - get(l - 1)) % (int)MOD + MOD) % MOD);
  return 0;
}