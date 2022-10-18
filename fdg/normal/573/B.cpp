#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

bool destr[100005];
vector<pair<int, int>> v;
vector<int> q;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    v.push_back({x, i});
  }
  sort(v.begin(), v.end());
  int qh = 0, ans = 0, p = 0;
  q = {0};
  if (n - 1) q.push_back(n - 1);
  destr[0] = destr[n - 1] = true;
  while (true) {
    ++ans;
    while (p < v.size() && v[p].first <= ans) {
      if (!destr[v[p].second]) {
        destr[v[p].second] = true;
        q.push_back(v[p].second);
      }
      ++p;
    }
    if (q.size() == n) break;
    int sz = q.size();
    while (qh < sz) {
      int x = q[qh++];
      if (x && !destr[x - 1]) {
        destr[x - 1] = true;
        q.push_back(x - 1);
      }
      if (x + 1 < n && !destr[x + 1]) {
        destr[x + 1] = true;
        q.push_back(x + 1);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}