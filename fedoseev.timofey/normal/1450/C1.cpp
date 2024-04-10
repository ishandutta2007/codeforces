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
    vector <int> cnt(3);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (a[i][j] == 'X') ++cnt[(i + j) % 3];
      }
    }
    int mn = 0;
    for (int i = 0; i < 3; ++i) if (cnt[i] < cnt[mn]) mn = i;
     for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (a[i][j] == 'X' && (i + j) % 3 == mn) a[i][j] = op(a[i][j]);
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