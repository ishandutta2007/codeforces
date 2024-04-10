#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[500005], ans[500005];
vector<pair<int, int>> q[500005];

int fen[500005];

void upd(int pos, int val) {
  for ( ; pos >= 0; pos = (pos & (pos + 1)) - 1)
    fen[pos] = min(fen[pos], val);
}

int fnd(int pos) {
  int ret = fen[pos];
  for ( ; pos <= 500000; pos |= pos + 1)
    ret = min(ret, fen[pos]);
  return ret;
}

map<int, int> f;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < m; ++i) {
    int l, r;
    scanf("%d%d", &l, &r); --l; --r;
    q[r].push_back({l, i});
  }
  for (int i = 0; i <= 500000; ++i)
    fen[i] = 1e+9;

  for (int i = 0; i < n; ++i) {
    if (f.count(arr[i])) {
      upd(f[arr[i]], i - f[arr[i]]);
    }
    for (auto p : q[i]) {
      ans[p.second] = fnd(p.first);
      if (ans[p.second] == 1e+9)
        ans[p.second] = -1;
    }
    f[arr[i]] = i;
  }

  for (int i = 0; i < m; ++i)
    printf("%d\n", ans[i]);
  return 0;
}