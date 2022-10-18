#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int n;
set<pair<int, int> > f;
vector<pair<int, int> > q;
vector<int> all;

pair<int, int> add(pair<int, int> p) {
  int pos = lower_bound(q.begin(), q.end(), make_pair(p.second, 0)) - q.begin();
  if (pos < q.size()) {
    p.second = max(p.second, q[pos].second);
    if (p.second > p.first) p.first = -1;
  } else {
    p.first = -1;
  }
  return p;
}

int main() {
  int m, x, y;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x, &y);
    f.insert(make_pair(x, y));
    all.push_back(x);
    if (x + 1 <= n)
      all.push_back(x + 1);
  }
  all.push_back(1);
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  q.push_back(make_pair(1, 1));
  for (int i = 0; i < all.size(); ++i) {
    int last = 0;
    set<pair<int, int>>::iterator it = f.lower_bound(make_pair(all[i], 0));
    vector<pair<int, int>> cur;
    while (it != f.end() && it->first == all[i]) {
      if (last + 1 <= it->second - 1)
        cur.push_back(add(make_pair(it->second - 1, last + 1)));
      last = it->second;
      ++it;
    }
    if (last + 1 <= n)
      cur.push_back(add(make_pair(n, last + 1)));
    sort(cur.begin(), cur.end());
    // for (auto p : cur)
    //   cout << p.first << "  " << p.second << endl;
    // cout << endl;
    q = cur;
  }
  if (q.back().first != n) {
    puts("-1");
    return 0;
  }
  printf("%d\n", 2 * n - 2);
  return 0;
}