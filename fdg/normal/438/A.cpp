#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int x[2002], y[2002], val[1002];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<pair<int, int> > v(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v[i].first);
    v[i].second = i;
    val[i] = v[i].first;
  }
  sort(v.rbegin(), v.rend());
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    --x[i]; --y[i];
  }
  long long ans = 0;
  bool used[1002] = {0};
  for (int i = 0; i < v.size(); ++i) {
    used[v[i].second] = true;
    for (int j = 0; j < m; ++j) {
      if (x[j] == v[i].second && !used[y[j]]) {
        ans += val[y[j]];
      }
      if (y[j] == v[i].second && !used[x[j]]) {
        ans += val[x[j]];
      }
    }
  }
  cout << ans << endl;
  return 0;
}