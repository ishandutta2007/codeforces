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
  int n;
  cin >> n;
  vector <pair <int, int>> ans;
  int mx = 1;
  for (int b = 1; (1 << b) <= n; ++b) {
    int cnt = n / (1 << b);
    int ukf = n - 1;
    int uks = n - 1 - (1 << (b - 1));
    for (int it = 0; it < cnt; ++it) {
      for (int i = 0; i < (1 << (b - 1)); ++i) {
        ans.push_back({ukf, uks});
        --ukf;
        --uks;
      }
      ukf -= (1 << (b - 1));
      uks -= (1 << (b - 1));
    }
    mx = (1 << b);
  }
  vector <vector <int>> groups;
  int uk = 0;
  for (int b = 0; (1 << b) < mx; ++b) {
    if (n & (1 << b)) {
      groups.push_back({});
      for (int i = 0; i < (1 << b); ++i) {
        groups.back().push_back(uk++);
      }
    }
  }
  vector <int> gs;
  for (int i = n - 1; i >= n - mx; --i) {
    gs.push_back(i);
  }
  reverse(groups.begin(), groups.end());
  while (groups.size() > 1) {
    int s = groups.rbegin()[0].size();
    if (s == (int)groups.rbegin()[1].size()) {
      for (int i = 0; i < s; ++i) {
        ans.push_back({groups.rbegin()[0][i], groups.rbegin()[1][i]});
      } 
      for (int x : groups.rbegin()[0]) {
        groups.rbegin()[1].push_back(x);
      }
      groups.pop_back();
    } else {
      for (int i = 0; i < s; ++i) {
        int x = gs.back();
        ans.push_back({groups.rbegin()[0][i], x});
        groups.rbegin()[0].push_back(x);
        gs.pop_back();
      }
    }
  } 
  cout << ans.size() << '\n';
  for (auto p : ans) {
    cout << p.first + 1 << ' ' << p.second + 1 << '\n';
  }
}