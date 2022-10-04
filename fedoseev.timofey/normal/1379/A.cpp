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
  string go = "abacaba";
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans;
    for (int i = 0; i + (int)go.size() <= n; ++i) {
      string t = s;
      bool bad = false;
      for (int j = 0; j < (int)go.size(); ++j) {
        if (t[i + j] != go[j] && t[i + j] != '?') {
          bad = true;
          break;
        }
        t[i + j] = go[j];
      }
      for (int i = 0; i < n; ++i) {
        if (t[i] == '?') t[i] = 'z';
      }
      int cnt = 0;
      for (int j = 0; j + (int)go.size() <= n; ++j) {
        if (t.substr(j, (int)go.size()) == go) ++cnt;
      }
      if (!bad && cnt == 1) {
        ans = t;
      }
    }
    if (!ans.empty()) {
      cout << "Yes\n";
      cout << ans << '\n';
    } else {
      cout << "No\n";
    }
  }
}