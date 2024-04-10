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
    vector <vector <int>> a(2);
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      a[i % 2].push_back(x);
    }
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());
    vector <int> b;
    for (int i = 0; i < (int)a[0].size(); ++i) {
      b.push_back(a[0][i]);
      if (i < (int)a[1].size()) b.push_back(a[1][i]);
    }
    if (is_sorted(b.begin(), b.end())) {
        cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}