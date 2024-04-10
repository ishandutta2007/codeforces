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
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    auto get_mex = [&] () {
      vector <int> have(n + 1);
      for (int i = 0; i < n; ++i) {
        if (a[i] <= n) have[a[i]] = 1;
      }
      for (int i = 0; i <= n; ++i) if (!have[i]) return i;
      assert(false);
    };
    vector <int> ans;
    while (!is_sorted(a.begin(), a.end())) {
      int x = get_mex();
      if (x < n) {
        ans.push_back(x);
        a[x] = x;
      } else {
        for (int i = 0; i < n; ++i) {
          if (a[i] != i) {
            a[i] = x;
            ans.push_back(i);
            break;
          }
        }
      }   
    } 
    cout << ans.size() << '\n';
    for (int i : ans) cout << i + 1 << ' ';
    cout << '\n';
  }
}