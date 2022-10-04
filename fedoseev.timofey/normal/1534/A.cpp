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
    vector <vector <char>> a(n, vector <char> (m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
      }
    }
    bool fnd = false;
    for (int tt = 0; tt <= 1; ++tt) {
      vector <vector <char>> b(n, vector <char> (m));
      int ok = 1;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if ((i + j) % 2 == tt) {
            b[i][j] = 'R';
          } else {
            b[i][j] = 'W';
          }
          ok &= (a[i][j] == '.' || a[i][j] == b[i][j]);
        }
      }
      if (ok) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < m; ++j) {
            cout << b[i][j];
          }
          cout << '\n';
        }
        fnd = true;
        break;
      } 
    }
    if (!fnd) cout << "NO\n";
  }
}