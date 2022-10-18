#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> allX, allY;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    allX.push_back(x);
  }
  for (int i = 0; i < m; ++i) {
    int x1, x2, y;
    scanf("%d%d%d", &x1, &x2, &y);
    if (x1 == 1)
      allY.push_back(x2);
  }
  allX.push_back(1000000000);
  sort(allX.begin(), allX.end());
  sort(allY.begin(), allY.end());
  
  int ans = n + m;

  for (int i = 0; i < allX.size(); ++i) {
    int pos = lower_bound(allY.begin(), allY.end(), allX[i]) - allY.begin();
    ans = min(ans, i + (int) allY.size() - pos);
  }

  printf("%d\n", ans);
  return 0;
}