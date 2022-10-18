#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int n, k;
int arr[200002];
map<int, int> f;

int rev(int x) {
  return (~x) & ((1 << k) - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0 ; i < n; ++i)
    cin >> arr[i];

  f[0]++;
  long long bad = 0;
  int xp = 0;
  for (int i = 0; i < n; ++i) {
    xp ^= arr[i];
    if (f[rev(xp)] < f[xp]) {
      xp = rev(xp);
    }
    bad += f[xp];
    f[xp]++;
  }

  cout << (1LL * n * (n + 1) / 2 - bad) << endl;
  return 0;
}