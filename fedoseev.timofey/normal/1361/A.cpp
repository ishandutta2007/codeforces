#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

const int N = 5e5 + 7;

vector <int> g[N];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector <int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&] (int i, int j) {
    return a[i] < a[j];
  });
  vector <int> c(n, -1);
  for (int i : p) {
    set <int> used;
    for (int j : g[i]) {
      used.insert(c[j]);
    }
    int uk = 1;
    while (used.count(uk)) ++uk;
    c[i] = uk;
  }
  if (c == a) {
    for (int i = 0; i < n; ++i) {
      cout << p[i] + 1 << ' ';
    }
    cout << '\n';
  } else {
    cout << "-1\n";
  }
}