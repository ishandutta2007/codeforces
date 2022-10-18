#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int ans = 1;
  for (int i = 0; i < n + m; ++i)
    ans = (ans + ans) % 998244353;
  cout << ans << endl;
  return 0;
}