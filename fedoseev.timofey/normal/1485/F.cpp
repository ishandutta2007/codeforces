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

const int md = 1e9 + 7;

void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector <ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
      pref[i + 1] = pref[i] + b[i];
    }
    vector <int> dp(n + 1);
    dp[0] = 1;
    int sum = 1;
    map <ll, int> cnt;
    cnt[0] = 1;
    for (int i = 1; i <= n; ++i) {
      dp[i] = sum;
      ll cur = b[i - 1] - pref[i];

      sub(sum, cnt[cur]);

      cnt[cur] = dp[i];
      add(sum, cnt[cur]);
    }
    /*for (int i = 0; i <= n; ++i) {
      cout << dp[i] << ' ';
    }
    cout << endl;*/
    cout << sum << '\n';
  }
}