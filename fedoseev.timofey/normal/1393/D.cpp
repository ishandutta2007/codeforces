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
#include <chrono>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 2007;

char a[N][N];
ull pref[N + N][N + N];
int mx[N][N];

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector <vector <char>> a(n, vector <char> (m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  vector <ull> go(26);
  for (int i = 0; i < 26; ++i) go[i] = rnd();
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x = i + j, y = i - j;
      pref[x + 1][y + m] += go[a[i][j] - 'a'];
    }
  }

  for (int i = 1; i < n + m; ++i) {
    for (int j = 1; j < n + m; ++j) {
      pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    }
  }

  ll ans = 0;
  for (char c = 'a'; c <= 'z'; ++c) {

    auto get = [&] (int x, int y, int l) {
      return pref[x + l][y + l] - pref[x + l][y] - pref[x][y + l] + pref[x][y];
    };

    auto test = [&] (int x, int y, int l) {
      int xx = x + y, yy = x - y + (m - 1);
      int ux = xx - l + 1, uy = yy - l + 1;
      if (ux < 0 || uy < 0) return false;
      int len = 2 * l - 1;
      if (ux + len >= n + m || uy + len >= n + m) return false;
      if (get(ux, uy, len) != go[c - 'a'] * ((len * len + 1) / 2)) return false;
      return true;
    };  

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j] != c) continue;
        if (i == 0) mx[i][j] = 1;
        else {
          if (a[i - 1][j] == c) {
            mx[i][j] = max(1, mx[i - 1][j] - 2);
            while (test(i, j, mx[i][j] + 1)) {
              ++mx[i][j];
            }
          } else {
            mx[i][j] = 1;
          }
        }
        ans += mx[i][j];
      }
    }
  }
  cout << ans << '\n';
}