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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int go = 0;
    vector <pair <char, int>> cnt;
    for (auto c : s) {
      if (c == 'W') ++go;
      if (cnt.empty() || cnt.back().first != c) cnt.push_back({c, 0});
      ++cnt.back().second;
    }
    if (go == 0) {
      cout << max(0, 2 * k - 1) << '\n';
      continue;
    }
    go += k;
    go = min(go, n);
    vector <int> have;
    for (int i = 1; i + 1 < (int)cnt.size(); ++i) {
      if (cnt[i - 1].first == 'W' && cnt[i].first == 'L' && cnt[i + 1].first == 'W') {
        have.push_back(cnt[i].second);
      }
    }
    sort(have.begin(), have.end());
    int cmp = (int)have.size() + 1;
    for (auto x : have) {
      if (k >= x) {
        k -= x;
        --cmp;
      }
    } 
    cout << 2 * go - cmp << '\n';
  }
}