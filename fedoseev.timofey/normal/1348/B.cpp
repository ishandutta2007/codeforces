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
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    set <int> have;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      have.insert(a[i]);
    }
    if ((int)have.size() > k) {
      cout << "-1\n";
      continue;
    }
    vector <int> ans;
    vector <int> go;
    while (true) {
      for (int x : have) {
        go.push_back(x);
        if ((int)go.size() == k) break;
      }
      if ((int)go.size() == k) break;
    }
    for (int i = 0; i < n; ++i) {
      for (int x : go) {
        ans.push_back(x);
      }
    }
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
    cout << '\n';
  }
}