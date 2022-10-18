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
  int n;
  scanf("%d", &n);
  long long arr[12][12] = {0};
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (i == 1 || j == 1) arr[i][j] = 1;
      else arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
  cout << arr[n][n] << endl;
  return 0;
}