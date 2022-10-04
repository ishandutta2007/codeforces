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
    vector <int> a(n);
    vector <int> cnt(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
      ++cnt[a[i]];
    }
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      mx = max(mx, cnt[i]);
    }
    if (mx > (n - mx) + 1) {
      cout << "-1\n";
      continue;
    }
    for (int i = 0; i < n; ++i) cnt[i] = 0;
    vector <pair <int, int>> gs;
    int lst = a[0];
    for (int i = 0; i < n; ++i) {
      if (i == n - 1 || a[i] == a[i + 1]) {
        ++cnt[lst];
        ++cnt[a[i]];
        lst = a[i];
      }
    }   
    int sum = 0;
    mx = 0;
    for (int i = 0; i < n; ++i) {
      sum += cnt[i];
      mx = max(mx, cnt[i]);
    }  
    int segs = sum / 2;
    int can = segs + 1;
    int new_segs = segs + max(0, mx - can);
    cout << new_segs - 1 << '\n';
  }
}