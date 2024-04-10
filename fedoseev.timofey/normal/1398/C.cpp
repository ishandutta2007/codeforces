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
    int n;
    cin >> n;
    map <int, int> cnt;
    int sum = 0;
    ++cnt[0];
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
      char c;
      cin >> c;
      sum += c - '0';
      ans += cnt[sum - i];
      ++cnt[sum - i];
    }
    cout << ans << '\n';
  }
}