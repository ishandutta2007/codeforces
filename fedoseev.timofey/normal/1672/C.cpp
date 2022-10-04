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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int fir = n, lst = -1;
    for (int i = 0; i + 1 < n; ++i) {
      if (a[i] == a[i + 1]) {
        fir = min(fir, i);
        lst = max(lst, i + 1);
      }
    }

    if (fir > lst || fir + 1 == lst) {
      cout << "0\n";
      continue;
    }

    cout << max(1, lst - fir - 2) << '\n';

    /*vector<pair<int, int>> a;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      if (a.empty() || a.back().first != x) a.push_back({x, 0});
      ++a.back().second;
    }*/
  }
}