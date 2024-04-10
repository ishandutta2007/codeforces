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
    int n, x;
    cin >> n >> x;
    map<int, int> cnt;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      mx = max(mx, a);
      ++cnt[a];
    }
    ll ans = 0;
    while (!cnt.empty()) {
      int go = cnt.begin()->first;
      vector<int> nums;
      while (true) {
        nums.push_back(go);
        if ((ll)go * x > mx) break;
        go *= x;
      }
      go = cnt.begin()->first;
      int have = cnt[go];
      for (int i = 1; i < (int)nums.size(); ++i) {
        int other = 0;
        if (cnt.count(nums[i])) {
          other = cnt[nums[i]];
        } else {
          other = 0;
        }
        int tk = min(have, other);
        ans += have - tk;
        have = other - tk;
      }
      ans += have;
      for (auto x : nums) {
        auto it = cnt.find(x);
        if (it != cnt.end()) cnt.erase(it);
      }
    }
    cout << ans << '\n';
  }   
}