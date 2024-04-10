#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int l[100005], r[100005], v[100005];

struct item {
  item(int _x, int _y1, int _y2, int _type) : x(_x), y1(_y1), y2(_y2), type(_type) {};
  int x, y1, y2, type;
};

bool operator < (const item& a, const item& b) {
  return a.x < b.x;
}

vector<item> q;
vector<int> all;

int get(int x) {
  return lower_bound(all.begin(), all.end(), x) - all.begin();
}

pair<int, int> tree[1200000];
int add[1200000];

void build(int i, int l, int r) {
  if (l == r) {
    tree[i] = make_pair(0, l);
    return;
  }
  int m = (l + r) >> 1;
  build(2 * i, l, m);
  build(2 * i + 1, m + 1, r);
  tree[i] = max(tree[2 * i], tree[2 * i + 1]);
}

void push(int i, int l, int r) {
  if (add[i] && l != r) {
    tree[2 * i].first += add[i];
    add[2 * i] += add[i];
    tree[2 * i + 1].first += add[i];
    add[2 * i + 1] += add[i];
  }
  add[i] = 0;
}

void update(int i, int l, int r, int L, int R, int val) {
  if (l == L && r == R) {
    add[i] += val;
    tree[i].first += val;
    return;
  }
  push(i, l, r);
  int m = (l + r) >> 1;
  if (R <= m) update(2 * i, l, m, L, R, val);
  else if (L > m) update(2 * i + 1, m + 1, r, L, R, val);
  else {
    update(2 * i, l, m, L, m, val);
    update(2 * i + 1, m + 1, r, m + 1, R, val);
  }
  tree[i] = max(tree[2 * i], tree[2 * i + 1]);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &l[i], &v[i], &r[i]);
    all.push_back(l[i]);
    all.push_back(r[i]);
    all.push_back(v[i]);
  }
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  for (int i = 0; i < n; ++i) {
    l[i] = get(l[i]);
    r[i] = get(r[i]);
    v[i] = get(v[i]);
    q.push_back(item(v[i], l[i], v[i], 1));
    q.push_back(item(r[i] + 1, l[i], v[i], -1));
  }
  build(1, 0, all.size() - 1);
  sort(q.begin(), q.end());
  pair<int, int> ans = make_pair(-1, 0);
  int L, R;
  for (int i = 0; i < q.size();) {
    int x = q[i].x;
    while (i < q.size() && q[i].x == x) {
      update(1, 0, all.size() - 1, q[i].y1, q[i].y2, q[i].type);
      ++i;
    }
    if (tree[1].first > ans.first) {
      ans = tree[1];
      L = tree[1].second;
      R = x;
    }
  }
  printf("%d\n", ans.first);
  // cout << all[L] << "  " << all[R] << endl;
  for (int i = 0; i < n; ++i) {
    if (L <= v[i] && v[i] <= R && l[i] <= L && R <= r[i])
      printf("%d ", i + 1);
  }
  printf("\n");
  return 0;
}