#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> v;

int main() {
  int n;
  scanf("%d", &n);
  v.resize(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &v[i]);
  sort(v.begin(), v.end());
  int ans = 0;
  long long tm = 0;
  for (int x : v) {
    if (x >= tm) {
      ans++;
      tm += x;
    }
  }
  printf("%d\n", ans);
  return 0;
}