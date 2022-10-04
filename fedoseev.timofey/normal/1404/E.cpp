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
 
const int N = 1e5 + 7;
vector <int> g[N];
int mt[N];
int used[N];

int timer = 1;

bool kuhn(int u) {
  if (used[u] == timer) return false;
  used[u] = timer;
  for (auto v : g[u]) {
    if (mt[v] == -1) {
      mt[v] = u;
      return true;
    }
  }
  for (auto v : g[u]) {
    if (kuhn(mt[v])) {
      mt[v] = u;
      return true;
    }
  }
  return false;
}

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
  int L = 0;
  vector <vector <vector <int>>> whoH(n, vector <vector <int>> (m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j + 1 < m; ++j) {
      if (a[i][j] == '#' && a[i][j + 1] == '#') {
        whoH[i][j].push_back(L);
        whoH[i][j + 1].push_back(L);
        ++L;
      }
    }
  }
  vector <vector <vector <int>>> whoV(n, vector <vector <int>> (m));
  int R = 0;
  for (int i = 0; i + 1 < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '#' && a[i + 1][j] == '#') {
        whoV[i][j].push_back(R);
        whoV[i + 1][j].push_back(R);
        ++R;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (auto x : whoH[i][j]) {
        for (auto y : whoV[i][j]) {
          g[x].push_back(y);
        }
      }
    }
  }
  for (int i = 0; i < N; ++i) mt[i] = -1;
  int have = 0;
  for (int i = 0; i < L; ++i) {
    if (kuhn(i)) {
      ++have;
      ++timer;
    } 
  }
  int mx = L + R - have;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '#') {
        ++ans;
      }
    }
  }
  cout << ans - mx << '\n';
}