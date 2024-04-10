#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<pair<int, int>> g[100002];
vector<int> ans1[100002], ans2[100002];
bool good1[100002], good2[100002];

int used1[100002], color1[100002], ok;
vector<int> changed;

void dfs1(int v, int ch) {
  color1[v] = ch;
  if (ch)
    changed.push_back(v);
  used1[v] = 1;
  for (auto e : g[v]) {
    if (!used1[e.first]) {
      dfs1(e.first, (ch ^ e.second));
    } else {
      if (color1[e.first] ^ color1[v] ^ e.second) {
        ok = false;
      }
    }
  }
}

vector<int> solve(int n) {
  vector<int> who;
  memset(used1, 0, sizeof(used1));
  memset(good1, 0, sizeof(good1));
  for (int i = 0; i < n; ++i) {
    if (!used1[i]) {
      who.push_back(i);
      ok = true;
      changed.clear();
      dfs1(i, 0);
      if (ok) {
        good1[i] = true;
        ans1[i] = changed;
      }
    }
  }

  memset(used1, 0, sizeof(used1));
  memset(good2, 0, sizeof(good2));
  for (int i = 0; i < n; ++i) {
    if (!used1[i]) {
      ok = true;
      changed.clear();
      dfs1(i, 1);
      if (ok) {
        good2[i] = true;
        ans2[i] = changed;
      }
    }
  }

  vector<int> ret;
  for (int x : who) {
    if (!good1[x] && !good2[x]) return vector<int> (n + 1);
    else if (!good1[x]) ret.insert(ret.end(), ans2[x].begin(), ans2[x].end());
    else if (!good2[x]) ret.insert(ret.end(), ans1[x].begin(), ans1[x].end());
    else {
      if (ans1[x].size() < ans2[x].size()) {
        ret.insert(ret.end(), ans1[x].begin(), ans1[x].end());
      } else {
        ret.insert(ret.end(), ans2[x].begin(), ans2[x].end());
      }
    }
  }
  return ret;
}

int main() {
  int n, m;
  scanf("%d%d\n", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x, y; char c;
    scanf("%d %d %c\n", &x, &y, &c); --x; --y;
    g[x].push_back({y, c == 'B'});
    g[y].push_back({x, c == 'B'});
  }

  vector<int> v1 = solve(n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < g[i].size(); ++j)
      g[i][j].second ^= 1;
  vector<int> v2 = solve(n);

  if (v2.size() < v1.size()) v1 = v2;

  if (v1.size() > n) cout << -1 << endl;
  else {
    sort(v1.begin(), v1.end());
    cout << v1.size() << endl;
    for (int x : v1)
      printf("%d ", x + 1);
    printf("\n");
  }

  return 0;
}