#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int mod = 1000000007;

pair<int, int> tree[400005];

vector<int> pos[100005];

void build(int i, int l, int r) {
  // cout << i << "  " << l << " " << r << endl;
  if (l == r) {
    tree[i] = {pos[l].back(), l};
    return;
  }

  int m = (l + r) >> 1;
  build(2 * i, l, m);
  build(2 * i + 1, m + 1, r);
  tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}

pair<int, int> find(int i, int l, int r, int L, int R) {
  if (l == L && r == R) {
    return tree[i];
  }

  int m = (l + r) >> 1;
  if (R <= m) return find(2 * i, l, m, L, R);
  if (L > m) return find(2 * i + 1, m + 1, r, L, R);

  return min(find(2 * i, l, m, L, m), find(2 * i + 1, m + 1, r, m + 1, R));
}

void update(int i, int l, int r, int x, int val) {
  if (l == r) {
    tree[i] = {val, x};
    return;
  }

  int m = (l + r) >> 1;
  if (x <= m) update(2 * i, l, m, x, val);
  else update(2 * i + 1, m + 1, r, x, val);
  tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}

struct item {
  int u, l, r, s;
};

bool operator < (const item &a, const item &b) {
  return a.u < b.u;
}

item v[100005];

map<pair<int, int>, int> what, f;

int h, w, n;

int calc(int H, int W) {
  if (f.count({H, W})) return f[{H, W}];

  if (what.count({H, W})) {
    int id = what[{H, W}];

    int ret = 0;
    if (v[id].l != 0) {
      ret += (1 + (v[id].r == w - 1)) * calc(v[id].u, v[id].l - 1);
    }
    if (v[id].r != w - 1) {
      ret += (1 + (v[id].l == 0)) * calc(v[id].u, v[id].r + 1);
    }
    if (ret >= mod) ret -= mod;
    return f[{H, W}] = ret;
  }

  return f[{H, W}] = 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> h >> w >> n;
  for (int i = 0; i < n; ++i) {
    cin >> v[i].u >> v[i].l >> v[i].r >> v[i].s;
    --v[i].u; --v[i].l; --v[i].r;
  }
  sort(v, v + n);

  for (int i = 0; i < w; ++i) {
    pos[i].push_back(h + mod);
    pos[i].push_back(h);
  }

  build(1, 0, w - 1);

  for (int i = n - 1; i >= 0; --i) {
    auto ret = find(1, 0, w - 1, v[i].l, v[i].r);
    while (ret.first <= v[i].u + v[i].s) {
      // cout << i << ": " << ret.first << " " << ret.second << endl;
      what[ret] = i;
      pos[ret.second].pop_back();
      update(1, 0, w - 1, ret.second, pos[ret.second].back());

      ret = find(1, 0, w - 1, v[i].l, v[i].r);
    }

    if (v[i].l != 0) {
      pos[v[i].l - 1].push_back(v[i].u);
      update(1, 0, w - 1, v[i].l - 1, v[i].u);
    }

    if (v[i].r != w - 1) {
      pos[v[i].r + 1].push_back(v[i].u);
      update(1, 0, w - 1, v[i].r + 1, v[i].u);
    }
  }

  int ans = 0;
  for (int i = 0; i < w; ++i) {
    ans += calc(h, i);
    if (ans >= mod) ans -= mod;
  }
  cout << ans << endl;

  return 0;
}