#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> g[100005];

int fatal = -1, fcnt = 0;

pair<int, int> go(int v, int par) {
  pair<int, int> ret(0, 0);
  int ch = 0;
  for (int x : g[v]) {
    if (x == par) continue;
    auto tmp = go(x, v);
    if (tmp.second > 1) fatal = x, fcnt++;
    if (tmp.second > 0 || tmp.first > 2 || g[x].size() != 1 && tmp.first != g[x].size() - 1) ret.second++;
    ret.first += tmp.first;
    ++ch;
  }
  if (ch == 0) ret.first++;
  // cout << v + 1 << "  " << ret.first << " " << ret.second << endl;
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  auto ret = go(0, -1);
  if (fatal == -1)
    puts(ret.second <= 2 ? "Yes" : "No");
  else {
    // cout << "Fatal: " << fatal + 1 << endl;
    int root = fatal;
    fatal = -1; fcnt = 0;
    ret = go(root, -1);
    // cout << fatal << "  " << fcnt << "  " << ret.first << " " << ret.second << endl;
    puts(fatal == -1 && ret.second <= 2 ? "Yes" : "No");
  }
  return 0;
}