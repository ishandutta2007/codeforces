#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

long long l[200004], r[200005];
vector<pair<long long, int>> v;

struct item {
  long long l, r;
  int ind;
};

bool operator < (const item &a, const item &b) {
  return a.l < b.l || a.l == b.l && a.r < b.r;
}

vector<item> all;

pair<long long, int> tree[800004];

void build(int i, int l, int r) {
  if (l == r) {
    tree[i] = {all[l].r, l};
    return;
  }
  int m = (l + r) >> 1;
  build(2 * i, l, m);
  build(2 * i + 1, m + 1, r);
  tree[i] = max(tree[2 * i + 1], tree[2 * i]);
}

pair<long long, int> find(int i, int l, int r, int L, int R, long long val) {
  if (l == L && r == R) {
    if (l == r)
      return tree[i];
  
    int m = (l + r) >> 1;
    if (tree[2 * i + 1].first >= val)
      return find(2 * i + 1, m + 1, r, m + 1, R, val);
    return find(2 * i, l, m, L, m, val);
  }

  int m = (l + r) >> 1;
  if (R <= m)
    return find(2 * i, l, m, L, R, val);
  if (L > m)
    return find(2 * i + 1, m + 1, r, L, R, val);

  auto p1 = find(2 * i + 1, m + 1, r, m + 1, R, val);
  if (p1.first >= val)
    return p1;
  return find(2 * i, l, m, L, m, val);
}

void update(int i, int l, int r, int pos) {
  if (l == r) {
    tree[i] = {-1, -1};
    return;
  }
  int m = (l + r) >> 1;
  if (pos <= m)
    update(2 * i, l, m, pos);
  else
    update(2 * i + 1, m + 1, r, pos);
  tree[i] = max(tree[2 * i + 1], tree[2 * i]);
}

int ans[200002];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%lld%lld", &l[i], &r[i]);
    if (i) {
      all.push_back({l[i] - r[i - 1], r[i] - l[i - 1], i});
    }
  }
  sort(all.begin(), all.end());
  // for (auto p : all)
  //   cout << p.l << " " << p.r << endl;

  build(1, 0, all.size() - 1);

  v.resize(m);
  for (int i = 0; i < m; ++i) {
    scanf("%lld", &v[i].first);
    v[i].second = i;
  }
  sort(v.rbegin(), v.rend());

  memset(ans, -1, sizeof(ans));
  int cnt = 0;
  for (auto x : v) {
    item it = {x.first + 1, -1, -1};
    int pos = lower_bound(all.begin(), all.end(), it) - all.begin() - 1;

    if (pos < 0)
      continue;

    auto res = find(1, 0, all.size() - 1, 0, pos, x.first);
    // cout << res.first << "  " << res.second << endl;
    if (res.first >= x.first) {
      ans[all[res.second].ind] = x.second;
      update(1, 0, all.size() - 1, res.second);
      ++cnt;
    }
  }
  
  if (cnt == all.size()) {
    puts("Yes");
    for (int i = 1; i < n; ++i)
      printf("%d ", ans[i] + 1);
    printf("\n");
  } else {
    puts("No");
  }
  return 0;
}