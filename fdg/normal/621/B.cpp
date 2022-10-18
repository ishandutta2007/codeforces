#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

map<int, int> f1, f2;

int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    ans += f1[x + y];
    f1[x + y]++;
    ans += f2[x - y];
    f2[x - y]++;
  }
  cout << ans << endl;
  return 0;
}