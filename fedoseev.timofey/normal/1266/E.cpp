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
 
using namespace std;
 
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  ll sum = 0;
  for (int i = 0; i < n; ++i) sum += a[i];
  int q;
  cin >> q;
  vector <int> cnt(n);
  int have = 0;
  map <pair <int, int>, int> go;

  for (int ts = 0; ts < q; ++ts) {
    int s, t, u;
    cin >> s >> t >> u;
    --s;
    --u;
    if (go.count({s, t})) {
      int v = go[{s, t}];
      have -= min(a[v], cnt[v]);
      --cnt[v];
      have += min(a[v], cnt[v]);
      go.erase({s, t});
    } 
    if (u != -1) {
      go[{s, t}] = u;
      have -= min(a[u], cnt[u]);
      ++cnt[u];
      have += min(a[u], cnt[u]);
    }
    cout << sum - have << '\n';
  }
}