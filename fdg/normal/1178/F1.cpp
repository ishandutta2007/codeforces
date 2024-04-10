#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int mod = 998244353;

int n, m;
int arr[505];

int mem[505][505];

int solve(int l, int r) {
  if (l >= r) return 1;
  if (mem[l][r] != -1) return mem[l][r];
  
  int index = l;
  for (int i = l; i <= r; ++i)
    if (arr[index] > arr[i])
      index = i;
  
  int ret1 = 0, ret2 = 0;
  for (int a = l; a <= index; ++a) {
    ret1 = (ret1 + 1LL * solve(l, a - 1) * solve(a, index - 1) % mod) % mod;
  }

  for (int b = index; b <= r; ++b) {
    ret2 = (ret2 + 1LL * solve(index + 1, b) * solve(b + 1, r) % mod) % mod;
  }
  return mem[l][r] = 1LL * ret1 * ret2 % mod;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i)
    cin >> arr[i];

  memset(mem, -1, sizeof(mem));
  cout << solve(0, m - 1) << endl;
  return 0;
}