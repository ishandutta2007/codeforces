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
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    if (u > v) {
      cout << "NO\n";
      continue;
    }
    vector <int> bu;
    for (int i = 0; i < 30; ++i) {
      if (u & (1 << i)) {
        bu.push_back(i);
      }
    }
    int ok = 1;
    for (int i = 29; i >= 0; --i) {
      if (v & (1 << i)) {
        while (!bu.empty() && bu.back() > i) bu.pop_back();
        if (bu.empty()) {
          ok = 0;
          break;
        }
        bu.pop_back();
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }     
}