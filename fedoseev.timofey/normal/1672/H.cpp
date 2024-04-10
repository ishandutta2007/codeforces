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
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<vector<int>> pref(2, vector<int>(n + 1));
  for (int i = 0; i < n; ++i) {
    pref[0][i + 1] = pref[0][i];
    pref[1][i + 1] = pref[1][i];
    ++pref[s[i] - '0'][i + 1];
  }
  vector<int> where(n);
  where[0] = -1;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i - 1]) where[i] = where[i - 1];
    else where[i] = i - 1;
  }
  vector<int> cmp(n);
  cmp[0] = 1;
  for (int i = 1; i < n; ++i) {
    cmp[i] = cmp[i - 1] + (s[i] != s[i - 1]);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    int ans = 1;

    int pl = where[l];
    int cnt_cmp = cmp[r] - (pl == -1 ? 0 : cmp[pl]); 
    int cmp0, cmp1;
    cmp0 = cmp1 = cnt_cmp / 2;
    if (cnt_cmp % 2 == 1 && s[r] == '0') {
      ++cmp0;
    } else if (cnt_cmp % 2 == 1 && s[r] == '1') {
      ++cmp1;
    }

    int cnt0 = pref[0][r + 1] - pref[0][l];
    int cnt1 = pref[1][r + 1] - pref[1][l];
    cnt0 -= cmp0;
    cnt1 -= cmp1;
    ans += max(cnt0, cnt1);
    cout << ans << '\n';
  }
}