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
    vector <int> p(n);
    vector <int> pos(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
      --p[i];
      pos[p[i]] = i;
    }
    vector <int> used(n);
    bool bad = false;
    for (int x = 0; x < n; ++x) {
      int id = pos[x];
      int need = x;
      while (id < n && !used[id]) {
        used[id] = 1;
        if (p[id] != need) {
          bad = true;
          break;
        }
        ++id;
        ++need;
      }
      if (bad) break;
    }
    if (bad) cout << "No\n";
    else cout << "Yes\n";
  }
}