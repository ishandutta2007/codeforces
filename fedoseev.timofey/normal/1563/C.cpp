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
#include <bitset>
#include <chrono>
 
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
    bool bad = false;
    vector <int> pos(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
      --p[i];
      pos[p[i]] = i;
      if (p[i] % 2 != i % 2) {
        bad = true;
      }
    }
    if (bad) {
      cout << "-1\n";
      continue;
    }
    vector <int> ans;
    auto op = [&] (int x) {
      if (x == 0) return;
      assert(1 <= x && x <= n);
      ans.push_back(x);
      for (int i = 0; i < x / 2; ++i) {
        swap(p[i], p[x - i - 1]);
        swap(pos[p[i]], pos[p[x - i - 1]]);
      }
    };
    int cnt = 0;
    for (int x = n - 1; x > 0; x -= 2) {
      int y = x - 1;
      op(pos[x] + 1);
      op(pos[y]);
      op(pos[y] + 2);
      op(3);
      op(n - cnt);
      cnt += 2;
    }
    for (int i = 1; i < n; ++i) {
      assert(p[i] > p[i - 1]);
    }
    cout << ans.size() << '\n';
    for (auto x : ans) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}