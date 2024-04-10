#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int val[100005];
vector<int> g[100005];

int out[100005], in[100005];
int rem[100005];

int pr[100005];

pair<int, int> dfs(int v, int par = -1) {
  pair<int, int> ret = make_pair(0, v);
  for (int u : g[v]) {
    if (u == par || rem[u]) continue;
    auto cur = dfs(u, v);
    cur.first++;
    if (cur.first > ret.first) {
      pr[u] = v;
      ret = cur;
    }
  }
  return ret;
}

int findCenter(int v) {
  // return v;
  auto ret = dfs(v);
  ret = dfs(ret.second);
  int k = ret.first / 2;
  while (k--) {
    ret.second = pr[ret.second];
  }
  return ret.second;
}

int mPow(int a, int x, int mod) {
  int ret = 1;
  while (x > 0) {
    if (x & 1) ret = 1LL * ret * a % mod;
    a = 1LL * a * a % mod;
    x >>= 1;
  }
  return ret;
}

int n, y, k, x;
int pwk[100005], rpwk[100005];

vector<pair<int, int>> pfrom[100005], pto[100005], all;
int height[100005];

namespace calc_out {

  void dfs(int v, int lev, int to, int pw, int cval, int h, int par = -1) {
    cval = (cval + 1LL * val[v] * pwk[pw]) % y;
    height[v] = h;
    // cout << to << endl;
    pfrom[to].push_back(make_pair(1LL * cval * rpwk[pw] % y, v));
    for (int u : g[v]) {
      if (rem[u] > lev && u != par) {
        dfs(u, lev, to, pw - 1, cval, h + 1, v);
      }
    }
  }

  void fillFrom(int u, int lev, int ver) {
    pfrom[u].clear();
    dfs(u, lev, u, 100000, 1LL * val[ver] * pwk[100001] % y, 1);
  }

  void dfs2(int v, int lev, int to, int pw, int cval, int par = -1) {
    cval = (cval + 1LL * val[v] * pwk[pw]) % y;
    // cout << to << endl;
    pto[to].push_back(make_pair(cval, v));
    all.push_back(make_pair(cval, v));
    for (int u : g[v]) {
      if (rem[u] > lev && u != par) {
        dfs2(u, lev, to, pw + 1, cval, v);
      }
    }
  }

  void fillTo(int u, int lev) {
    pto[u].clear();
    dfs2(u, lev, u, 0, 0);
    sort(pto[u].begin(), pto[u].end());
  }

  int get(const vector<pair<int, int>>& v, int val) {
    int ret = upper_bound(v.begin(), v.end(), make_pair(val, n + 5)) - lower_bound(v.begin(), v.end(), make_pair(val, -1));
    return ret;
  }

  int stupid(int v, int lev, int pw, int cval = 0, int par = -1) {
    cval = (cval + 1LL * val[v] * pwk[pw]) % y;
    int ret = (cval == x);
    for (int u : g[v]) {
      if (u != par && rem[u] > lev)
        ret += stupid(u, lev, pw + 1, cval, v);
    }
    return ret;
  }

  void go(int v, int lev) {
    v = findCenter(v);
    rem[v] = lev;
    for (int u : g[v]) {
      if (!rem[u]) {
        go(u, lev + 1);
      }
    }
    all.clear();
    for (int u : g[v]) {
      if (rem[u] > lev) {
        fillFrom(u, lev, v);
        fillTo(u, lev);
      }
    }
    all.push_back(make_pair(0, v));
    sort(all.begin(), all.end());
    for (int u : g[v]) {
      if (rem[u] > lev) {
        for (auto it : pfrom[u]) {
          int need = 1LL * (x - it.first + y) * rpwk[height[it.second] + 1] % y;
          // if (v == 1 && u == 0)
          //   cout << need << " " << it.first << "  " << it.second << endl;
          out[it.second] += get(all, need) - get(pto[u], need);
        }
      }
    }
    out[v] += stupid(v, lev, 0);
  }
};

namespace calc_in {

  void dfs(int v, int lev, int to, int pw, int cval, int h, int par = -1) {
    cval = (cval + 1LL * val[v] * pwk[pw]) % y;
    height[v] = h;
    // cout << to << endl;
    pfrom[to].push_back(make_pair((x - 1LL * cval * rpwk[pw] % y + y) * rpwk[h + 1] % y, v));
    all.push_back(make_pair((x - 1LL * cval * rpwk[pw] % y + y) * rpwk[h + 1] % y, v));
    for (int u : g[v]) {
      if (rem[u] > lev && u != par) {
        dfs(u, lev, to, pw - 1, cval, h + 1, v);
      }
    }
  }

  void fillFrom(int u, int lev, int ver) {
    pfrom[u].clear();
    dfs(u, lev, u, 100000, 1LL * val[ver] * pwk[100001] % y, 1);
    sort(pfrom[u].begin(), pfrom[u].end());
  }

  void dfs2(int v, int lev, int to, int pw, int cval, int par = -1) {
    cval = (cval + 1LL * val[v] * pwk[pw]) % y;
    // cout << to << endl;
    pto[to].push_back(make_pair(cval, v));
    for (int u : g[v]) {
      if (rem[u] > lev && u != par) {
        dfs2(u, lev, to, pw + 1, cval, v);
      }
    }
  }

  void fillTo(int u, int lev) {
    pto[u].clear();
    dfs2(u, lev, u, 0, 0);
    // sort(pto[u].begin(), pto[u].end());
  }

  int get(const vector<pair<int, int>>& v, int val) {
    int ret = upper_bound(v.begin(), v.end(), make_pair(val, n + 5)) - lower_bound(v.begin(), v.end(), make_pair(val, -1));
    return ret;
  }

  int stupid(int v, int lev, int pw, int cval = 0, int par = -1) {
    cval = (cval + 1LL * val[v] * pwk[pw]) % y;
    int ret = (1LL * cval * rpwk[pw] % y == x);
    for (int u : g[v]) {
      if (u != par && rem[u] > lev)
        ret += stupid(u, lev, pw - 1, cval, v);
    }
    return ret;
  }

  void go(int v, int lev) {
    v = findCenter(v);
    rem[v] = lev;
    for (int u : g[v]) {
      if (!rem[u]) {
        go(u, lev + 1);
      }
    }
    all.clear();
    for (int u : g[v]) {
      if (rem[u] > lev) {
        fillFrom(u, lev, v);
        fillTo(u, lev);
      }
    }
    all.push_back(make_pair(1LL * (x - val[v] + y) * rpwk[1] % y, v));
    sort(all.begin(), all.end());
    for (int u : g[v]) {
      if (rem[u] > lev) {
        for (auto it : pto[u]) {
          int need = it.first; //1LL * (x - 1LL * it.first + y) % y;
          // if (v == 1 && u == 0)
          //   cout << need << " " << it.first << "  " << it.second << endl;
          in[it.second] += get(all, need) - get(pfrom[u], need);
        }
      }
    }
    in[v] += stupid(v, lev, 100001);
  }
};

void go(int st, int v, int par = -1, int res = 0, int len = 0) {
  res = (res + 1LL * val[v] * pwk[len]) % y;
  if (res == x) in[v]++, out[st]++;
  for (int u : g[v]) {
    if (u != par) {
      go(st, u, v, res, len + 1);
    }
  }
}

int main() {
  scanf("%d%d%d%d", &n, &y, &k, &x);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &val[i]);
  }
  pwk[0] = rpwk[0] = 1;
  for (int i = 1; i <= 100001; ++i) {
    pwk[i] = 1LL * pwk[i - 1] * k % y;
    if (i > 1)
      rpwk[i] = 1LL * rpwk[i - 1] * rpwk[1] % y;
    else
      rpwk[1] = mPow(pwk[i], y - 2, y);
  }
  for (int i = 1; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  // for (int i = 0; i < n; ++i)
  //   go(i, i);
  int lev = 1;
  calc_out::go(0, 1);
  memset(rem, 0, sizeof(rem));
  calc_in::go(0, 1);
  // for (int i = 0; i < n; ++i)
  //   cout << out[i] << " ";
  // cout << endl;

  // for (int i = 0; i < n; ++i)
  //   cout << in[i] << " ";
  // cout << endl;

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += 2LL * (out[i]) * (n - out[i]) + 2LL * (in[i]) * (n - in[i]) + 1LL * (out[i]) * (n - in[i]) + 1LL * (n - out[i]) * (in[i]);
  } 
  cout << 1LL * n * n * n - ans / 2 << endl;
  return 0;
}