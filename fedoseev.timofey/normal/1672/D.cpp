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
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
      --b[i];
    }
    vector<int> cnt(n);
    int uk = 0;
    bool bad = false;
    for (int i = 0; i < n; ++i) {
      while (uk < n && a[uk] != b[i]) {
        ++cnt[a[uk]];
        ++uk;
      }
      if (uk == n) {
        bad = true;
        break;
      } 
      if (uk < n && a[uk] == b[i] && cnt[b[i]] > 0) {
        --cnt[b[i]];
      } else {
        ++uk;
      }
    }
    if (!bad) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}