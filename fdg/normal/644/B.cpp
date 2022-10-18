#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <map>
#include <set>

using namespace std;

long long ans[200005];

int main() {
  int n, b;
  scanf("%d%d", &n, &b);
  queue<pair<int, int>> q;
  long long tm = 0;
  for (int i = 0; i < n; ++i) {
    int t, d;
    scanf("%d%d", &t, &d);
    while (q.size() && tm <= t) {
      tm += q.front().first;
      ans[q.front().second] = tm;
      q.pop();
    }
    if (tm <= t && q.size() == 0) {
      tm = t + d;
      ans[i] = tm;
    } else if (q.size() < b) {
      q.push({d, i});
    }
  } 
  while (q.size()) {
      tm += q.front().first;
      ans[q.front().second] = tm;
      q.pop();
    }
  for (int i = 0; i < n; ++i) {
    if (i) printf(" ");
    if (ans[i] == 0) ans[i] = -1;
    printf("%lld", ans[i]);
  }
  printf("\n");
  return 0;
}