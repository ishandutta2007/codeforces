#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> what[200005], all[200005];

int sgn(int x) {
  return (x > 0) - (x < 0);
}

int ans[200002], removed[200002];

void rem(vector<int> &v, int x) {
  for (int i = (int)v.size() - 1; i >= 0; --i) {
    if (abs(v[i]) == abs(x))
      v.erase(v.begin() + i);
  }
}

void rem2(vector<pair<int, int>> &v, int x) {
  for (int i = (int)v.size() - 1; i >= 0; --i) {
    if (abs(v[i].second) == abs(x))
      v.erase(v.begin() + i);
  }
}

vector<pair<int, int>> g[200002];
int deg[200002], used[200002];

map<pair<int, int>, int> f;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; ++j) {
      int a;
      scanf("%d", &a);
      what[abs(a)].push_back(sgn(a) * i);
      all[i].push_back(a);
    }
  }

  vector<int> q;
  for (int i = 1; i <= m; ++i) {
    if (what[i].size() < 2 || sgn(what[i][0]) == sgn(what[i][1])) {
      q.push_back(i);
      removed[i] = true;
    }
  }

  for (int i = 0; i < q.size(); ++i) {
    int x = q[i];
    if (what[x].size() < 2 || sgn(what[x][0]) == sgn(what[x][1])) {
      ans[x] = what[x].size() == 0 || sgn(what[x][0]) == 1;
      for (int j : what[x]) {
        for (int e : all[abs(j)]) {
          rem(what[abs(e)], abs(j));
          if (!removed[abs(e)] && what[abs(e)].size() < 2) {
            q.push_back(abs(e));
            removed[abs(e)] = true;
          }
        }
      }
    }
  }

  for (int i = 1; i <= m; ++i) {
    if (removed[i]) continue;
    // cout << what[i][0] << " " << what[i][1] << endl;
    g[abs(what[i][0])].push_back({abs(what[i][1]), i * sgn(what[i][0])});
    g[abs(what[i][1])].push_back({abs(what[i][0]), i * sgn(what[i][1])});
    deg[abs(what[i][0])]++;
    deg[abs(what[i][1])]++;
    // f[{abs(what[i][0]), abs(what[i][1])}] = i * sgn(what[i][0]);
    // f[{abs(what[i][1]), abs(what[i][0])}] = i * sgn(what[i][1]);
  }

  q.clear();
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 1) {
      q.push_back(i);
      used[i] = true;
    }
  }

  int pos = 0, h = 0;
  while (pos <= n || h < q.size()) {
    while (h < q.size()) {
      int x = g[q[h]][0].second;
      // cout << "P: " << pos << " " << x << " " << q[h] << "  " << g[q[h]][0].first << endl;
      rem2(g[g[q[h]][0].first], x);
      ans[abs(x)] = sgn(x) == 1;
      // cout << "ANS: " << x << " " << sgn(x) << endl;
      deg[g[q[h]][0].first]--;
      if (deg[g[q[h]][0].first] == 1 && !used[g[q[h]][0].first]) {
        q.push_back(g[q[h]][0].first);
        used[g[q[h]][0].first] = true;
      }
      ++h;
    }
    while (pos <= n) {
      if (!used[pos] && deg[pos] > 1) {
        q.push_back(pos);
        used[pos] = true;
        // cout << pos << endl;
        ++pos;
        break;
      }
      ++pos;
    }
  }

  for (int i = 1; i <= n; ++i) {
    bool ok = false;
    for (int j : all[i]) {
      if ((sgn(j) == 1) == ans[abs(j)])
        ok = true;
    }
    if (!ok) {
      puts("NO");
      return 0;
    }
  }

  puts("YES");
  for (int i = 1; i <= m; ++i)
    printf("%d", ans[i]);
  printf("\n");
  return 0;
}