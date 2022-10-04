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
  int n, d, m;
  cin >> n >> d >> m;
  vector <int> good, bad;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x > m) {
      bad.push_back(x);
    } else {
      good.push_back(x);
    }
  }
  sort(good.begin(), good.end());
  sort(bad.begin(), bad.end());
  int k = bad.size();
  vector <ll> suf(k + 1);
  for (int i = k - 1; i >= 0; --i) {
    suf[i] = suf[i + 1] + bad[i];
  }
  ll ans = 0;
  ll sum_good = 0;
  for (int cnt_good = 0; cnt_good <= (int)good.size(); ++cnt_good) {
    int rem = (int)good.size() - cnt_good;
    int l = 0, r = (int)bad.size() + 1;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      int have = rem + (int)bad.size() - m;
      if ((ll)d * (m - 1) <= have) {
        l = m;
      } else {
        r = m;
      }
    }
    ans = max(ans, sum_good + suf[k - l]);
    if (cnt_good < (int)good.size()) sum_good += good[(int)good.size() - cnt_good - 1]; 
  }
  cout << ans << '\n';
}