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
    vector <int> a(m), b(m), c(m);
    vector <int> used(n);
    for (int i = 0; i < m; ++i) {
      cin >> a[i] >> b[i] >> c[i];
      --a[i], --b[i], --c[i];
      used[b[i]] = 1;
    }
    for (int i = 0; i < n; ++i) {
      if (!used[i]) {
        for (int j = 0; j < n; ++j) {
          if (j == i) continue;
          cout << i + 1 << ' ' << j + 1 << '\n';
        }
        break;
      }
    }
  }
}