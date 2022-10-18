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

struct item {
  item() : sum(0), val(0), sx(0) {};
  int sum, val, sx;
};

item tree[4 * 300000 + 5];

item merge(int la, int ra, item a, const item& b) {
  a.val = (a.val + b.val + 1LL * b.sum * (ra - la + 1)) % mod;
  a.sum += b.sum;
  if (a.sum >= mod) a.sum -= mod;
  a.sx += b.sx;
  if (a.sx >= mod) a.sx -= mod;
  return a;
}

item find(int i, int l, int r, int L, int R) {
  if (l == L && r == R) {
    return tree[i];
  }
  int m = (l + r) >> 1;
  if (R <= m) return find(2 * i, l, m, L, R);
  else if (L > m) return find(2 * i + 1, m + 1, r, L, R);
  return merge(L, m, find(2 * i, l, m, L, m), find(2 * i + 1, m + 1, r, m + 1, R));
}

void update(int i, int l, int r, int pos, int x, int k) {
  if (l == r) {
    tree[i].sum += k;
    if (tree[i].sum >= mod) tree[i].sum -= mod;
    // tree[i].val += k;
    // if (tree[i].val >= mod) tree[i].val -= mod;
    tree[i].sx += x;
    if (tree[i].sx >= mod) tree[i].sx -= mod;
    return;
  }
  int m = (l + r) >> 1;
  if (pos <= m) update(2 * i, l, m, pos, x, k);
  else update(2 * i + 1, m + 1, r, pos, x, k);
  tree[i] = merge(l, m, tree[2 * i], tree[2 * i + 1]);
}

int sz[300005], p[300005];
vector<int> g[300005];

int dfs(int v) {
  int cnt = 1;
  for (int u : g[v]) {
    cnt += dfs(u);
  }
  for (int u : g[v]) {
    if (2 * sz[u] >= cnt) {
      p[u] = v + 1;
    } else {
      p[u] = -(v + 1);
    }
  }
  return sz[v] = cnt;
}

bool used[300005];
int pl[300005], vpath[300005], vpos[300005], pcnt, tcnt;
int ind[300005];

void dfs2(int v) {
  for (int u : g[v]) {
    dfs2(u);
  }
  if (!used[v]) {
    vpath[v] = pcnt;
    pl[pcnt] = tcnt;
    ind[tcnt] = v;
    vpos[v] = tcnt++;
    used[v] = true;
    while (p[v] >= 0) {
      v = p[v] - 1;
      used[v] = true;
      vpath[v] = pcnt;
      // pl[pcnt] = tcnt;
      ind[tcnt] = v;
      vpos[v] = tcnt++;
    }

    ++pcnt;
  }
}

int main() {
  int n, q, a;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d", &a); --a;
    g[a].push_back(i);
  }
  memset(p, -1, sizeof(p));
  dfs(0);
  dfs2(0);
  pl[pcnt] = tcnt;
  // cout << pcnt << endl;
  // for (int i = 0; i < n; ++i)
  //   cout << i << "  " << vpath[i] << "  " << vpos[i] << endl;
  // for (int i = 0; i < pcnt; ++i)
  //   cout << pl[i] << endl;
  // return 0;
  scanf("%d", &q);
  int v, x, k, t;
  while (q--) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d%d", &v, &x, &k); --v;
      update(1, 0, n - 1, vpos[v], x, k);
    } else {
      scanf("%d", &v); --v;
      int ans = 0, add = 0;
      while (true) {
        // cout << "V: " << v << endl;
        // cout << vpos[v] << "  " << pl[vpath[v] + 1] - 1 << endl;
        item cur = find(1, 0, n - 1, vpos[v], pl[vpath[v] + 1] - 1);
        // cout << "R:  " << cur.sx << "  " << cur.val << "  " << cur.sum << " " << add << endl;
        ans = (ans + cur.sx - cur.val - 1LL * cur.sum * add) % mod;
        add += pl[vpath[v] + 1] - vpos[v];
        if (v == 0) break;
        v = ind[pl[vpath[v] + 1] - 1];
        // cout << "VV:  " << v << endl;
        if (v == 0) break;
        // cout << "P: " << p[1] << endl;
        v = -p[v] - 1;
      }
      if (ans < 0) ans += mod;
      printf("%d\n", ans);
    }
  }
  return 0;
}