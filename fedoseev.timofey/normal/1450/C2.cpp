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
    vector <vector <char>> a(n, vector <char> (n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
      }
    }
    auto op = [&] (char c) {
      if (c == 'X') return 'O';
      if (c == 'O') return 'X';
      assert(false);
    };
    vector <int> cntX(3);
    vector <int> cntO(3);
    int all = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (a[i][j] == 'X') {
          ++cntX[(i + j) % 3];
          ++all;
        }
        if (a[i][j] == 'O') {
          ++cntO[(i + j) % 3];
          ++all;
        }
      }
    }
    int f = -1, s = -1;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (i == j) continue;
        if (3 * (cntX[i] + cntO[j]) <= all) {
          f = i;
          s = j;
        }
      }
    }
    assert(f != -1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (a[i][j] == 'X' && (i + j) % 3 == f) {
          a[i][j] = op(a[i][j]);
        } else if (a[i][j] == 'O' && (i + j) % 3 == s) {
          a[i][j] = op(a[i][j]);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << a[i][j];
      }
      cout << '\n';
    } 
  }
}