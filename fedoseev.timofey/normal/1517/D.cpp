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
 
const int N = 507;
const int K = 11;
const int Inf = 1e9;

int dw[N][N], rg[N][N];
int ans[N][N];
int best[K][N][N];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j + 1 < m; ++j) {
      cin >> rg[i][j];
    }
  }
  for (int i = 0; i + 1 < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> dw[i][j];
    }
  }
  if (k % 2 == 1) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << "-1 ";
      }
      cout << '\n';
    }
    exit(0);
  }
  k /= 2;
  
  auto ok = [&] (int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
  };
  for (int it = 0; it < k; ++it) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        best[it + 1][i][j] = Inf;
      }
    }
    for (int x = 0; x < n; ++x) {
      for (int y = 0; y < m; ++y) {
        for (int dx = -1; dx <= 1; ++dx) {
          for (int dy = -1; dy <= 1; ++dy) {
            if (abs(dx) + abs(dy) != 1) continue;
            if (!ok(x + dx, y + dy)) continue;
            int delta;
            if (dx == 1) delta = dw[x][y];
            if (dx == -1) delta = dw[x - 1][y];
            if (dy == 1) delta = rg[x][y];
            if (dy == -1) delta = rg[x][y - 1];
            best[it + 1][x][y] = min(best[it + 1][x][y], best[it][x + dx][y + dy] + delta);
          }
        }
      }
    }
  }
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << 2 * best[k][i][j] << ' ';
    }
    cout << '\n';
  }
}