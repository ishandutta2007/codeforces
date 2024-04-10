#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> ans[10002];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);

  int p = 5;
  for (int i = 0; i < n; ++i) {
    ans[i].push_back(p - 4);
    ans[i].push_back(p - 2);
    ans[i].push_back(p - 1);
    ans[i].push_back(p);
    p += 6;
  }
  cout << (5 + (n - 1) * 6) * k << endl;

  for (int i = 0; i < n; ++i) {
    printf("%d %d %d %d\n", ans[i][0] * k, ans[i][1] * k, ans[i][2] * k, ans[i][3] * k);
  }
  return 0;
}