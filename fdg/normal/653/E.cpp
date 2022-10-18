#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

set<int> f[300002], lft;
vector<int> q;
bool used[300005];

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    f[a].insert(b);
    f[b].insert(a);
  }

  for (int i = 1; i < n; ++i)
    lft.insert(i);

  int should = 0, can = 0;
  for (int i = 1; i < n; ++i) {
    if (!f[i].count(0)) {
      ++can;
      if (f[i].size() == n - 2) {
        ++should;
        used[i] = true;
        q.push_back(i);
        lft.erase(i);
      }
    }
  }

  if (should > k || can < k) {
    puts("impossible");
    return 0;
  }

  int qh = 0, p0 = 1;

  while (q.size() < n - 1) {
    while (qh < q.size()) {
      int v = q[qh]; ++qh;

      set<int>::iterator it = lft.begin(), nx;
      while (it != lft.end()) {
        if (f[v].count(*it)) break;
        nx = it; ++nx;
        used[*it] = true;
        q.push_back(*it);
        lft.erase(it);
        it = nx;
      }

      for (int x : f[v]) {
        it = lft.upper_bound(x);
        while (it != lft.end()) {
          if (f[v].count(*it)) break;
          nx = it; ++nx;
          used[*it] = true;
          q.push_back(*it);
          lft.erase(it);
          it = nx;
        }
      }
    }

    if (qh == q.size() && q.size() < n - 1) {
      bool fnd = false;
      while (p0 < n && !fnd) {
        if (!f[0].count(p0) && lft.count(p0)) {
          used[p0] = true;
          q.push_back(p0);
          lft.erase(p0);
          fnd = true;
        }
        ++p0;
      }
      if (!fnd) {
        puts("impossible");
        return 0;
      }
      ++should;
    }
  }

  if (should > k) {
    puts("impossible");
    return 0;
  }
  
  puts("possible");

  return 0;
}