#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N = (int) 2e5 + 7;
int n, need[N];
vector<int> g[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) {
      int l;
      cin >> l;
      for (int k = 1; k <= l; k++) {
        int j; cin >> j; g[j].push_back(i);
      }
      need[i] = l;
    }
    set<int> free;
    for (int i = 1; i <= n; i++) {
      if (need[i] == 0) {
        free.insert(i);
      }
    }
    int done = 0, lastpos = 1, steps = 1;
    while (!free.empty()) {

      done++;
      auto it = free.lower_bound(lastpos);
      if (it == free.end()) it = free.begin(), steps++;
      int i = *it;
      lastpos = i;
      free.erase(i);
      for (auto &j : g[i]) {
        need[j]--;
        if (need[j] == 0) free.insert(j);
      }
    }
    if (done < n) steps = -1;
    cout << steps << "\n";
  }

  return 0;
}