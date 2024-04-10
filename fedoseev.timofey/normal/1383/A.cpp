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
    string a, b;
    cin >> a >> b;
    bool bad = false;
    vector <vector <int>> go(20, vector <int> (20));
    for (int i = 0; i < n; ++i) {
      if (a[i] > b[i]) {
        bad = true;
      }
      if (a[i] != b[i]) go[a[i] - 'a'][b[i] - 'a'] = 1;
    }
    if (bad) {
      cout << "-1\n";
    } else {
      bool ch = true;
      while (ch) {
        ch = false;
        for (int i = 0; i < 20; ++i) {
          for (int j = i + 1; j < 20; ++j) {
            for (int k = j + 1; k < 20; ++k) {
              if (go[i][j] && go[i][k]) {
                go[i][k] = 0;
                go[j][k] = 1;
                ch = true;
              }
            }
          }
        }
        for (int i = 19; i >= 0; --i) {
          for (int j = i - 1; j >= 0; --j) {
            for (int k = j - 1; k >= 0; --k) {
              if (go[j][i] && go[k][i]) {
                go[k][i] = 0;
                go[k][j] = 1;
                ch = true;
              }
            }
          }
        }
      }
      int ans = 0;
      for (int i = 0; i < 20; ++i) {
        for (int j = i + 1; j < 20; ++j) {
          if (go[i][j]) {
            ++ans;
          }
        }
      }
      cout << ans << '\n';
    }
  }
}