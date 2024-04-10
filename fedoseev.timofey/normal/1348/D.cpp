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
    --n;
    vector <int> ans;
    int have = 1;
    while (true) {
      if (4LL * have <= n) {
        ans.push_back(have);
        have *= 2;
        n -= have;
      } else {
        if (2LL * have >= n) {
          ans.push_back(n - have);
          break;
        } else {
          int f = n / 2;
          int s = n - f;
          assert(f >= have);
          ans.push_back(f - have);
          ans.push_back(s - f);
          break;
        }
      }
    }
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
    cout << '\n';
  }
}