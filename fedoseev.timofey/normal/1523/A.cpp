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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int it = 0; it < m; ++it) {
      string ns = s;
      for (int i = 0; i < n; ++i) {
        if (s[i] == '1') continue;
        int cnt = 0;
        if (i > 0 && s[i - 1] == '1') ++cnt;
        if (i + 1 < n && s[i + 1] == '1') ++cnt;
        if (cnt == 1) {
          ns[i] = '1';
        }
      }
      if (s == ns) break;
      s = ns;
    }
    cout << s << '\n';
  }
}