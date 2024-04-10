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
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    bool fl = false;
    for (int b = 30; b >= 0; --b) {
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] & (1 << b)) {
          ++cnt;
        }
      }
      if (cnt % 2 == 1) {
        if (cnt % 4 == 1) {
          cout << "WIN\n";
        } else {
          if ((n - cnt) % 2 == 0) {
            cout << "LOSE\n";
          } else {
            cout << "WIN\n";
          }
        }
        fl = true;
        break;
      }
    }
    if (!fl) {
      cout << "DRAW\n";
    }
  }
}