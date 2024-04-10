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
    string s;
    cin >> s;
    vector <pair <int, int>> bl;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      if (bl.empty() || bl.back().first != s[i] - '0') {
        bl.push_back({s[i] - '0', 0});
      }
      ++bl.back().second;
    }
    vector <int> have;
    for (auto p : bl) if (p.first == 1) have.push_back(p.second);
    sort(have.rbegin(), have.rend());
    int ans = 0;
    for (int i = 0; i < (int)have.size(); i += 2) ans += have[i];
    cout << ans << '\n';
  } 
}