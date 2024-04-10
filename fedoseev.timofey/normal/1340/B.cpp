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

vector <string> nm = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, k;
  cin >> n >> k;
  vector <string> have(n);
  for (int i = 0; i < n; ++i) cin >> have[i];
  vector <vector <int>> dp(n + 1, vector <int> (k + 1));
  dp[n][0] = 1;
  auto need = [&] (int id, int x) {
    bool bad = false;
    int cnt = 0;
    for (int i = 0; i < 7; ++i) {
      if (have[id][i] == '1' && nm[x][i] == '0') {
        bad = true;
        break;
      }
      if (have[id][i] == '0' && nm[x][i] == '1') {
        ++cnt;
      }
    }
    if (bad) return -1;
    else return cnt;
  };
  for (int i = n - 1; i >= 0; --i) {
    for (int x = 0; x < 10; ++x) {
      int cr = need(i, x);
      if (cr != -1) {
        for (int j = 0; j + cr <= k; ++j) {
          dp[i][j + cr] |= dp[i + 1][j];
        }
      }
    }
  }
  if (dp[0][k] == 0) {
    cout << "-1\n";
    return 0;
  }
  string ans;
  int rem = k;
  for (int i = 0; i < n; ++i) {
    for (int x = 9; x >= 0; --x) {
      int cr = need(i, x);
      if (cr != -1) {
        if (cr <= rem && dp[i + 1][rem - cr]) {
          ans += char('0' + x);
          rem -= cr;
          break;
        }
      }
    }
  }
  cout << ans << '\n';
}