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
    int n, m;
    cin >> n >> m;
    vector <vector <int>> b(n, vector <int> (m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> b[i][j];
      }
    }
    vector <pair <int, int>> gs(n * m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        gs[i * m + j] = {i, j};
      }
    }
    sort(gs.begin(), gs.end(), [&] (pair <int, int> f, pair <int, int> s) {
      return b[f.first][f.second] < b[s.first][s.second];
    });
    vector <vector <int>> ans(n, vector <int> (m, -1));
    vector <vector <int>> used(n, vector <int> (m));
    for (int i = 0; i < m; ++i) {
      ans[gs[i].first][i] = gs[i].second;
      used[gs[i].first][gs[i].second] = 1;
    }
    for (int i = 0; i < n; ++i) {
      int uk = 0;
      for (int j = 0; j < m; ++j) {
        if (ans[i][j] == -1) {
          while (used[i][uk]) ++uk;
          ans[i][j] = uk;
          used[i][uk] = 1;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << b[i][ans[i][j]] << ' ';
      }
      cout << '\n';
    }
  }
}