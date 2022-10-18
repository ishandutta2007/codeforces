#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

struct vertex {
  int next[22], go[22];
  bool leaf;
  int p;
  char pch;
  int link;
  int val, dp;
};
 
vertex t[2002];
int sz;
 
void init() {
  t[0].p = t[0].link = -1;
  memset(t[0].next, -1, sizeof(t[0].next));
  memset(t[0].go, -1, sizeof(t[0].go));
  t[0].val = 0;
  t[0].dp = -1;
  sz = 1;
}
 
void add_string (const vector<int> & s, int val) {
  int v = 0;
  for (size_t i=0; i<s.size(); ++i) {
    int c = s[i];
    if (t[v].next[c] == -1) {
      memset(t[sz].next, -1, sizeof(t[sz].next));
      memset(t[sz].go, -1, sizeof(t[sz].go));
      t[sz].link = -1;
      t[sz].p = v;
      t[sz].pch = c;
      t[sz].val = 0;
      t[sz].dp = -1;
      t[v].next[c] = sz++;
    }
    v = t[v].next[c];
  }
  t[v].leaf = true;
  t[v].val += val;
  // cout << "V: " << v << " " << t[v].val << endl;
}
 
int go (int v, int c);
 
int get_link (int v) {
  if (t[v].link == -1)
    if (v == 0 || t[v].p == 0)
      t[v].link = 0;
    else
      t[v].link = go (get_link (t[v].p), t[v].pch);
  return t[v].link;
}
 
int go (int v, int c) {
  if (t[v].go[c] == -1)
    if (t[v].next[c] != -1)
      t[v].go[c] = t[v].next[c];
    else
      t[v].go[c] = v==0 ? 0 : go (get_link (v), c);
  return t[v].go[c];
}

int calc(int v) {
  if (t[v].dp != - 1) return t[v].dp;
  int ret = t[v].val;
  if (v != 0)
    ret += calc(get_link(v));
  return t[v].dp = ret;
}

int mod = 1000000007, k, m;
int dp[2][2][201][202][502];

void upd(int& r, int a) {
  r += a;
  if (r >= mod) r -= mod;
}

int solve(const vector<int>& vec, bool LS = false) {
  if (LS)
    memset(dp, 0, sizeof(dp));
  dp[0][0][0][0][0] = 1;
  for (int len = 0; len < vec.size(); ++len) {
    for (int ls = 0; ls < 2; ++ls) {
      for (int has = 0; has < 2; ++has) {
        for (int v = 0; v < sz; ++v) {
          for (int sum = 0; sum <= k; ++sum) {
            if (dp[ls][has][len][v][sum]) {
              for (int d = 0; d <= (ls ? (m - 1) : vec[len]); ++d) {
                int nv = v, nsum = sum;
                if (has || (d > 0))
                  nv = go(v, d), nsum = sum + calc(nv);
                if (sum <= k)
                  upd(dp[ls || (d < vec[len])][has || (d > 0)][len + 1][nv][nsum], dp[ls][has][len][v][sum]);
              }
            }
          }
        }
      }
    }
  }
  int ans = 0;
  for (int ls = 1; ls >= 0; --ls) {
    for (int sum = 0; sum <= k; ++sum)
      for (int v = 0; v < sz; ++v) {
        upd(ans, dp[ls][1][vec.size()][v][sum]);
      }
    if (LS) break;
  }
  return ans;
}

vector<int> l, r;
vector<int> str[22];
int val[22], nval[22], need[22];

int main() {
  int n;
  scanf("%d%d%d", &n, &m, &k);
  int len = 0, a;
  scanf("%d", &len);
  for (int i = 0; i < len; ++i) {
    scanf("%d", &a);
    l.push_back(a);
  }
  scanf("%d", &len);
  for (int i = 0; i < len; ++i) {
    scanf("%d", &a);
    r.push_back(a);
  }

  init();

  for (int i = 0; i < n; ++i) {
    scanf("%d", &len);
    for (int j = 0; j < len; ++j) {
      scanf("%d", &a);
      str[i].push_back(a);
    }
    scanf("%d", &val[i]);
    add_string(str[i], val[i]);
  }
  for (int i = 0; i < sz; ++i) {
    calc(i);
    // cout << i << "  " << calc(i) << endl;
  }
  int ans = solve(r) - solve(l, true);
  if (ans < 0) ans += mod;
  cout << ans << endl;
/*  for (int i = 0; i < n; ++i) {
    nval[i] += val[i];
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      for (int p = 0; p + str[j].size() <= str[i].size(); ++p) {
        bool ok = false;
        for (int t = 0; t < str[j].size(); ++t) {
          if (str[j][t] != str[i][p + t]) {
            ok = false;
            break;
          }
        }
        if (ok) {
          nval[i] += val[j];
          need[j] = 1;
        }
      }
    }
  }*/
  return 0;
}