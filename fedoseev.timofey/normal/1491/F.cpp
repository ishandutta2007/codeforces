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
  //freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> gs;
    auto ask = [&] (vector <int> a, vector <int> b) {
      if (a.empty() || b.empty()) return 0;
      cout << "? " << a.size() << ' ' << b.size() << endl;
      for (auto x : a) cout << x + 1 << ' ';
      cout << endl;
      for (auto x : b) cout << x + 1 << ' ';
      cout << endl;
      int res;
      cin >> res;
      return res;
    };  
    vector <int> ans;
    int non_zero = -1;
    for (int i = 0; i < n; ++i) {
      if (non_zero != -1) {
        int cur = ask({non_zero}, {i});
        if (cur == 0) ans.push_back(i); 
      } else {
        int cur = ask({i}, gs); 
        if (cur == 0) {
          gs.push_back(i);
          continue;
        } else {
          non_zero = i;
          int l = 0, r = (int)gs.size() + 1;
          while (r - l > 1) {
            int m = (l + r) >> 1;
            vector <int> rofl;
            for (int j = 0; j < m; ++j) rofl.push_back(gs[j]);
            int x = ask(rofl, {i});
            if (x) r = m;
            else l = m;
          } 
          for (int i = 0; i < l; ++i) ans.push_back(gs[i]);
          for (int i = l + 1; i < (int)gs.size(); ++i) ans.push_back(gs[i]);
          gs.clear();
        } 
      }
    } 
    cout << "! " << ans.size() << endl;
    for (auto x : ans) cout << x + 1 << ' ';
    cout << endl; 
  }   
}