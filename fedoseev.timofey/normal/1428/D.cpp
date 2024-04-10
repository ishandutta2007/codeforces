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
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector <pair <int, int>> ans;
  vector <pair <int, int>> g2, g1, g3;
  int free = n - 1;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] == 0) continue;
    if (a[i] == 1) {
      ans.push_back({free, i});
      g1.push_back({free, i});
      --free;
    } else if (a[i] == 2) {
      if (g1.empty()) {
        cout << "-1\n";
        exit(0);
      }
      auto p = g1.back();
      g1.pop_back();
      ans.push_back({p.first, i});
      g2.push_back({p.first, i});
    } else {
      if (!g3.empty()) {
        auto p = g3.back();
        g3.pop_back();
        ans.push_back({free, i});
        ans.push_back({free, p.second});
        g3.push_back({free, i});
        --free;
      } else if (!g2.empty()) {
        auto p = g2.back();
        g2.pop_back();
        ans.push_back({free, i});
        ans.push_back({free, p.second});
        g3.push_back({free, i});
        --free;
      } else if (!g1.empty()) {
        auto p = g1.back();
        g1.pop_back();
        ans.push_back({free, i});
        ans.push_back({free, p.second});
        g3.push_back({free, i});
        --free;
      } else {
        cout << "-1\n";
        exit(0); 
      }
    }
  }   
  cout << ans.size() << '\n';
  for (auto p : ans) {
    cout << p.first + 1 << ' ' << p.second + 1 << '\n';
  }
}