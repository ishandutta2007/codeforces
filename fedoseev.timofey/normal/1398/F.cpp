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
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; ++i) {
    s += '0';
  }

  vector <int> c0(n + 1), c1(n + 1);
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '0' || s[i] == '?') c0[i] = c0[i + 1] + 1;
    else c0[i] = 0;
  }
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '1' || s[i] == '?') c1[i] = c1[i + 1] + 1;
    else c1[i] = 0;
  }
  vector <int> c(n);
  for (int i = 0; i < n; ++i) c[i] = max(c0[i], c1[i]);
  priority_queue <int, vector <int>, greater <int>> q;
  for (int i = 1; i <= n; ++i) q.push(i);
  vector <vector <int>> alive(n);
  vector <int> ans(n + 1);
  for (int i = 0; i < n; ++i) {
    for (auto y : alive[i]) q.push(y);
    int x = c[i];
    while (!q.empty() && q.top() <= x) {
      int y = q.top();
      q.pop();
      ++ans[y];
      if (i + y < n) alive[i + y].push_back(y);
    }
  }
  for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}