#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;
const int N = 2e5 + 5;

int fp[N];

struct SegTree {
  int n;
  vector<long long> val;
  SegTree(int _n) : n(_n), val(2 * n, 1) {}

  void update(int x, int y, long long v, int id, int l, int r) {
    if (x >= r || l >= y) return;
    if (x <= l && r <= y) {
      val[id] = val[id] * v % mod;
      return;
    }
    int mid = (l + r) >> 1, il = id + 1, ir = id + (mid-l) * 2;
    update(x, y, v, il, l, mid);
    update(x, y, v, ir, mid, r);
  }

  void update(int x, int y, long long v) {
    update(x, y, v, 0, 0, n);
  }

  long long get(int id, int l, int r) {
    if (r-l < 2) {
      return val[id];
    }
    int mid = (l + r) >> 1, il = id + 1, ir = id + (mid-l) * 2;
    return val[id] * (get(il, l, mid) + get(ir, mid, r)) % mod;
  }

  long long get() {
    return get(0, 0, n);
  }
};

vector<vector<int>> g;
vector<vector<tuple<int, int, int>>> diff;
vector<int> in, out, par, nodes;

void dfs(int v) {
  in[v] = nodes.size();
  nodes.push_back(v);
  for (int u : g[v]) {
    if (u == par[v]) continue;
    par[u] = v;
    dfs(u);
  }
  out[v] = nodes.size();
}

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod) {
    if (p & 1)
      r = r * b % mod;
  }
  return r;
}

void solve() {
  int n;
  cin >> n;
  g.resize(n);
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  diff.resize(n+1);
  for (int i = 0; i <= n; ++i)
    diff[i].clear();
  for (int i = 0; i < n-1; ++i) {
    int u, v, x, y;
    cin >> u >> v >> x >> y;
    --u, --v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
    int d = __gcd(x, y);
    x /= d;
    y /= d;
    while (x > 1) {
      int p = fp[x], c = 0;
      while (fp[x] == p) {
        x /= p;
        ++c;
      }
      diff[p].emplace_back(u, v, c);
    }
    while (y > 1) {
      int p = fp[y], c = 0;
      while (fp[y] == p) {
        y /= p;
        ++c;
      }
      diff[p].emplace_back(v, u, c);
    }
  }
  in.resize(n);
  out.resize(n);
  par.assign(n, 0);
  nodes.clear();
  dfs(0);
  SegTree tree(n);
  vector<int> all, cnt;
  for (int p = 1; p <= n; ++p) {
    if (diff[p].empty()) continue;
    all.clear();
    all.push_back(0);
    all.push_back(n);
    for (auto [u, v, c] : diff[p]) {
      all.push_back(max(in[u], in[v]));
      all.push_back(min(out[u], out[v]));
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    cnt.assign(all.size(), 0);
    for (auto [u, v, c] : diff[p]) {
      int lef = max(in[u], in[v]), rig = min(out[u], out[v]);
      lef = lower_bound(all.begin(), all.end(), lef) - all.begin();
      rig = lower_bound(all.begin(), all.end(), rig) - all.begin();
      if (in[u] >= in[v]) {
        cnt[lef] += c;
        cnt[rig] -= c;
      } else {
        cnt[0] += c;
        cnt[lef] -= c;
        cnt[rig] += c;
      }
    }
    int mini = cnt[0];
    for (int i = 0; i+1 < (int)all.size(); ++i) {
      cnt[i+1] += cnt[i];
      mini = min(cnt[i], mini);
    }
    for (int i = 0; i+1 < (int)all.size(); ++i) {
      tree.update(all[i], all[i+1], powmod(p, cnt[i] - mini));
    }
  }
  long long ans = tree.get();
  cout << ans << '\n';
}

int main() {
  for (int i = 2; i < N; ++i) {
    if (fp[i]) continue;
    for (int j = i; j < N; j += i) {
      if (fp[j]) continue;
      fp[j] = i;
    }
  }
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}