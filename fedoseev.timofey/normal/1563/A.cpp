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
    int a, b;
    cin >> a >> b;
    set <int> ans;
    for (int who = 0; who <= 1; ++who) {
      /*int mx = min(a, (a + b + 1) / 2) + min(b, (a + b) / 2);
      int mn = max(0, a - (a + b) / 2) + max(0, b - (a + b + 1) / 2);
      for (int x = mn; x <= mx; ++x) ans.insert(x);*/
      for (int a1 = 0; a1 <= a; ++a1) {
        int a2 = a - a1;
        int b2 = (a + b + 1) / 2 - a1;
        int b1 = b - b2;
        if (0 <= a1 && 0 <= a2 && 0 <= b1 && 0 <= b2 && (a2 + b1) == (a + b) / 2) {
          ans.insert(a1 + b1);
        } 
      }
      swap(a, b);
    }
    cout << ans.size() << '\n';
    for (auto x : ans) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}