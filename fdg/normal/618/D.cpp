#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <ctime>

using namespace std;

int deg[200005], td[200005];
vector<int> g[200005];

bool used[200005];

int n, x, y;
long long ans = 0;
vector<int> path;

void dfs(int v) {
  used[v] = true;
  path.push_back(v);
  for (int u : g[v]) {
    if (!used[u]) {
      dfs(u);
    }
  }
}

set<pair<int, int>> f;

long long calc(vector<int> &v) {
  long long ret = 0;
  for (int i = 1; i < v.size(); ++i) {
    if (f.count({v[i - 1], v[i]})) ret += x;
    else ret += y;
  }
  return ret;
}

long long go(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q, int x) {
  // cout << x << endl;
  memset(used, 0, sizeof(used));
  vector<int> v(1, x);
  for (int u : g[x]) {
    deg[u]--;
    q.push({deg[u], u});
    deg[x]--;
  }
  used[x] = true;

  while (q.size()) {
    x = v.back();

    set<int> leafs;
    while (q.size()) {
      if (deg[q.top().second] != q.top().first || used[q.top().second]) {
        q.pop();
        continue;
      }

      // cout << q.top().first << "  " << q.top().second << endl;
      if (q.top().first > 1) break;
      leafs.insert(q.top().second);
      q.pop();
    }

    // cout << leafs.size() << endl;

    int nx = *leafs.begin();
    for (int u : leafs) {
      if (!f.count({x, u})) {
        nx = u;
        break;
      }
    }
    v.push_back(nx);
    for (int u : leafs) {
      if (u != nx) {
        // cout << u << endl;
        v.push_back(u);
      }

      for (int uu : g[u]) {
        if (used[uu] || leafs.count(uu)) continue;
        deg[uu]--;
        q.push({deg[uu], uu});
        deg[u]--;
      }

      used[u] = true;
    }
  }

  long long ans = calc(v);
  v.insert(v.begin(), v.back());
  v.pop_back();
  ans = min(ans, calc(v));

  return calc(v);
}

int dp[2][200002];

int solve(int v, bool us, int par) {
  if (dp[us][v] != -1) return dp[us][v];

  int &ret = dp[us][v]; ret = 0;
  if (us) {
    int cnteq = 0;
    for (int x : g[v]) {
      if (x != par) {
        ret += max(solve(x, 0, v), solve(x, 1, v));
        if (solve(x, 0, v) == solve(x, 1, v)) ++cnteq;
      }
    }
    ret += min(2, cnteq);
  } else {
    vector<int> best, pref, suf, who;
    for (int x : g[v]) {
      if (x != par) {
        best.push_back(max(solve(x, 0, v), solve(x, 1, v)));
        who.push_back(x);
      }
    }
    pref = suf = best;
    for (int i = 1; i < pref.size(); ++i)
      pref[i] += pref[i - 1];
    for (int i = suf.size() - 2; i >= 0; --i)
      suf[i] += suf[i + 1];

    for (int i = 0; i < who.size(); ++i) {
      int cur = 1 + solve(who[i], 0, v);
      if (i) cur += pref[i - 1];
      if (i + 1 < suf.size()) cur += suf[i + 1];
      ret = max(ret, cur);
    }
  }

  // cout << v << "  " << us << "  " << ret << endl;

  return ret;
}

int main() {
  scanf("%d%d%d", &n, &x, &y);
  for (int i = 1; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
    deg[a]++; deg[b]++;
    f.insert({a, b});
    f.insert({b, a});
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

  for (int i = 0; i < n; ++i) {
    q.push({deg[i], i});
  }

  // cout << q.top().first << "  " << q.top().second << endl;

  if (x < y) {
    // dfs(q.top().second);
    // ans = calc(path);
    memset(dp, -1, sizeof(dp));
    int V = q.top().second;
    int cnt = max(solve(V, 0, -1), solve(V, 1, -1));
    // cout << cnt << endl;
    ans = 1LL * cnt * x + 1LL * (n - 1 - cnt) * y;
  } else {
    bool hasOne = false;
    for (int i = 0; i < n; ++i)
      if (deg[i] == n - 1) hasOne = true;
    if (!hasOne) {
      ans = 1LL * (n - 1) * y;
    } else {
      ans = 1LL * (n - 2) * y + x;
    }

    // for (int i = 0; i < n; ++i) td[i] = deg[i];

    // srand(time(NULL));
    // ans = go(q, q.top().second);
    // for (int it = 0; it < 22; ++it) {
    //   int ver = rand() % n;
    //   if (deg[ver] > 1) continue;
    //   for (int i = 0; i < n; ++i) deg[i] = td[i];
    //   ans = min(ans, go(q, ver));
    // }
  }

  cout << ans << endl;

  return 0;
}