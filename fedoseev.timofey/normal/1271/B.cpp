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
  string cur = s;
  vector <int> ans;
  for (int i = 0; i + 1 < n; ++i) {
    if (s[i] == 'B') {
      ans.push_back(i);
      s[i] = 'W';
      if (s[i + 1] == 'B') s[i + 1] = 'W';
      else s[i + 1] = 'B';
    }
  }
  if (s.back() == 'W') {
    cout << ans.size() << '\n';
    for (int x : ans) cout << x + 1 << ' ';
    return 0;
  }
  s = cur;
  ans.clear();

  for (int i = 0; i + 1 < n; ++i) {
    if (s[i] == 'W') {
      ans.push_back(i);
      s[i] = 'B';
      if (s[i + 1] == 'B') s[i + 1] = 'W';
      else s[i + 1] = 'B';
    }
  }
  if (s.back() == 'B') {
    cout << ans.size() << '\n';
    for (int x : ans) cout << x + 1 << ' ';
    return 0;
  }
  cout << "-1\n";
}