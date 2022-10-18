#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int a[300002], b[300002];

long long ans[300002];
vector<pair<int, int>> v;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  
  long long totalB = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    v.push_back({a[i] - b[i], i});
    totalB += b[i];
  }
  sort(v.begin(), v.end());

  long long curA = 0;
  for (int i = 0; i < n; ++i) {
    int who = v[i].second;
    totalB -= b[who];
    ans[who] = (curA + 1LL * i * b[who]) + (totalB + 1LL * (n - 1 - i) * a[who]);
    curA += a[who];
  }

  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x; --y;
  
    int val = min(a[x] + b[y], a[y] + b[x]);
    ans[x] -= val;
    ans[y] -= val;
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}