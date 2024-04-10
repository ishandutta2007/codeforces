#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int t[2002], h[2002], m[2002];

int go(int n, int k, int tp) {
  int ret = 0;
  bool used[2002] = {0};
  while (true) {
    int ind = -1;
    for (int i = 0; i < n; ++i) {
      if (!used[i] && t[i] == tp && h[i] <= k && (ind == -1 || m[i] > m[ind]))
        ind = i;
    }
    if (ind == -1) break;
    used[ind] = true;
    k += m[ind];
    ++ret; tp ^= 1;
  }
  return ret;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &t[i], &h[i], &m[i]);
  }
  cout << max(go(n, k, 0), go(n, k, 1)) << endl;
  return 0;
}