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
    vector <vector <int>> r(n, vector <int> (5));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 5; ++j) {
        cin >> r[i][j];
      }
    }
    int who = 0;
    for (int i = 1; i < n; ++i) {
      int cnt = 0;
      for (int j = 0; j < 5; ++j) {
        if (r[who][j] < r[i][j]) {
          ++cnt;
        }
      }
      if (cnt < 3) {
        who = i;
      }
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (who == i) continue;
      int cnt = 0;
      for (int j = 0; j < 5; ++j) {
        if (r[who][j] < r[i][j]) {
          ++cnt;
        }
      }
      if (cnt < 3) {
        ok = false;
      }
    }
    if (ok) {
      cout << who + 1 << '\n';
    } else {
      cout << "-1\n";
    }
  }
}