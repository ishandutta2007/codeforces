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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string s;
    cin >> s;
    int n = s.size();
    int cnt_a = 0, cnt_b = 0;
    for (auto c : s) {
      if (c == 'A') ++cnt_a;
      else ++cnt_b;
    }
    if (cnt_a != a + c + d || cnt_b != b + c + d) {
      cout << "NO\n";
      continue;
    }
    int cnt_ab = 0;
    for (int i = 0; i + 1 < n; ++i) {
      if (s[i] == 'A' && s[i + 1] == 'B') {
        ++cnt_ab;
        ++i;
      }
    }
    vector<vector<vector<int>>> who(2, vector<vector<int>>(2));
    for (int i = 0; i < n; ++i) {
      int r = i;
      while (r + 1 < n && s[r + 1] != s[r]) ++r;
      if (r - i + 1 >= 2) {
        who[s[i] - 'A'][s[r] - 'A'].push_back(r - i + 1);
      }
      i = r;
    }
    int cnt_ba = 0;
    sort(who[1][0].begin(), who[1][0].end());
    for (auto x : who[1][0]) {
      if (cnt_ba + x / 2 <= d) {
        cnt_ba += x / 2;
        cnt_ab -= x / 2 - 1;
      } else {
        int need = d - cnt_ba;
        cnt_ba += need;
        cnt_ab -= need;
      }
    }
    for (auto x : who[0][0]) {
      int tk = min(d - cnt_ba, x / 2);
      cnt_ba += tk;
      cnt_ab -= tk;
    }
    for (auto x : who[1][1]) {
      int tk = min(d - cnt_ba, x / 2);
      cnt_ba += tk;
      cnt_ab -= tk;
    }
    sort(who[0][1].rbegin(), who[0][1].rend());
    for (auto x : who[0][1]) {
      if (cnt_ba < d) {
        --cnt_ab;
        int tk = min(d - cnt_ba, x / 2 - 1);
        cnt_ba += tk;
        cnt_ab -= tk;
      }
    }
    if (cnt_ab >= c && cnt_ba >= d) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}