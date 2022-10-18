#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<vector<int>> g;
vector<bool> isMy;
set<int> other;

vector<bool> used;

int find(int v) {
  if (used[v]) return -1;

  if (isMy[v]) return v;

  used[v] = true;
  for (int x : g[v]) {
    int val = find(x);
    if (val != -1)
      return val;
  }

  return -1;
}

int main() {
  int T;
  cin >> T;
  
  while (T--) {
    int n;
    cin >> n;

    g.clear();
    g.resize(n);

    isMy.clear();
    isMy.resize(n, false);

    other.clear();

    used.clear();
    used.resize(n, false);

    for (int i = 1; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      g[x].push_back(y);
      g[y].push_back(x);
    }

    int k1;
    cin >> k1;
    for (int i  = 0; i < k1; ++i) {
      int x;
      cin >> x;
      --x;
      isMy[x] = true;
    }

    int k2;
    cin >> k2;
    for (int i  = 0; i < k2; ++i) {
      int x;
      cin >> x;
      --x;
      other.insert(x);
    }

    cout << "B " << (*other.begin()) + 1 << endl;
    int start;
    cin >> start;
    --start;

    int cand = find(start);
    cout << "A " << cand + 1 << endl;
    int who;
    cin >> who;
    --who;

    if (other.count(who)) {
      cout << "C " << cand + 1 << endl;
    } else {
      cout << "C " << -1 << endl;
    }
  }
  return 0;
}