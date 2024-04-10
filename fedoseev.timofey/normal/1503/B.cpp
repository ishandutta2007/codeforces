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
  //freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <vector <pair <int, int>>> pos(2);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      pos[(i + j) % 2].push_back({i, j});
    }
  }
  for (int tt = 0; tt < n * n; ++tt) {
    int c;
    cin >> c;
    --c;
    int id = -1, col = -1;
    if (c == 2) {
      if (!pos[0].empty()) {
        id = 0;
        col = 0;
      } else {
        id = 1;
        col = 1;
      }
    } else {
      if (!pos[c ^ 1].empty()) {
        id = c ^ 1;
        col = c ^ 1;
      } else {
        id = c;
        col = 2;
      }
    }
    cout << col + 1 << ' ';
    cout << pos[id].back().first + 1 << ' ' << pos[id].back().second + 1 << endl;
    pos[id].pop_back();
  }
}