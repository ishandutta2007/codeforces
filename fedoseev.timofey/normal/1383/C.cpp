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

const int K = 20;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector <vector <int>> go(K, vector <int> (K));
    for (int i = 0; i < n; ++i) {
      go[a[i] - 'a'][b[i] - 'a'] = 1;
    }
    vector <int> used(K);
    int ans = 0;
    auto solve = [&] (vector <int> c) {
      sort(c.begin(), c.end());
      int k = c.size();
      vector <int> gogo(k);
      for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
          if (go[c[i]][c[j]]) gogo[i] |= (1 << j);
        }
      }
      vector <int> ok(1 << k);
      ok[0] = 1;
      for (int mask = 1; mask < (1 << k); ++mask) {
        for (int i = 0; i < k; ++i) {
          if (mask & (1 << i)) {
            int nmask = mask ^ (1 << i);
            if ((nmask & gogo[i]) == 0) {
              ok[mask] |= ok[nmask];
            }
          }
        }
      }
      int mx = 0;
      for (int mask = 0; mask < (1 << k); ++mask) {
        if (ok[mask]) {
          mx = max(mx, __builtin_popcount(mask));
        }
      }
      return 2 * k - mx - 1;
    };    
    for (int i = 0; i < K; ++i) {
      if (!used[i]) {
        vector <int> c;
        queue <int> q;
        used[i] = 1;
        q.push(i);
        while (!q.empty()) {
          int u = q.front();
          q.pop();
          c.push_back(u);
          for (int v = 0; v < K; ++v) {
            if (!used[v] && (go[u][v] || go[v][u])) {
              used[v] = 1;
              q.push(v);
            }
          }
        }
        ans += solve(c);
      } 
    } 
    cout << ans << '\n';
  } 
}