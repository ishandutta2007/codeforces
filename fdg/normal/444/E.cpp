#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<pair<int, pair<int, int>>> v;

int dsu[3002], sz[3002], sum[3002];

int repr(int x) {
  return x == dsu[x] ? x : dsu[x] = repr(dsu[x]);
}

void join(int a, int b) {
  a = repr(a); b = repr(b);
  if (a != b) {
    dsu[a] = b;
    sz[b] += sz[a];
    sum[b] += sum[a];
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    --a; --b;
    v.push_back(make_pair(c, make_pair(a, b)));
  }
  int total = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &sum[i]);
    total += sum[i];
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; ++i) {
    dsu[i] = i;
    sz[i] = 1;
  }
  int ans = v.size() > 0 ? v[0].first : 0;
  for (int i = 0; i < v.size(); ++i) {
    join(v[i].second.first, v[i].second.second);
    bool ok = true;
    for (int j = 0; j < n; ++j) {
      if (sz[repr(j)] > total - sum[repr(j)]) {
        ok = false;
        break;
      }
    }
    if (ok) ans = v[i + 1].first;
  }
  printf("%d\n", ans);
  return 0;
}