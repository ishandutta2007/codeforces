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
    vector <vector <int>> a(n, vector <int> (m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
      }
    }
    vector <vector <int>> b(m, vector <int> (n));
    for (int j = 0; j < m; ++j) {
      for (int i = 0; i < n; ++i) {
        cin >> b[j][i];
      }
    }
    vector <int> where(n * m + 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        where[a[i][j]] = i;
      }
    }
    vector <int> ord;
    for (int i = 0; i < n; ++i) {
      ord.push_back(where[b[0][i]]);
    }
    vector <vector <int>> ans;
    for (int x : ord) {
      ans.push_back(a[x]);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << ans[i][j] << ' ';
      }
      cout << '\n';
    }
  } 
}