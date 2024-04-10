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
    ll l, r;
    cin >> n >> l >> r;
    --l, --r;
    int len = r - l + 1;
    ll all = 0;
    vector <int> ans;
    ll sum = 0;
    bool go = false;
    for (int v = 0; v + 1 < n; ++v) {
      if ((int)ans.size() == len) break;
      if (go) {
        for (int w = v + 1; w < n; ++w) {
          if ((int)ans.size() == len) break;
          ans.push_back(v);
          if ((int)ans.size() == len) break;
          ans.push_back(w);
          if ((int)ans.size() == len) break;
        }
      } else {
        int have = (n - v - 1) * 2;
        if (sum + have <= l) {
          sum += have;
        } else {
          for (int w = v + 1; w < n; ++w) {
            if ((int)ans.size() == len) break;
            if (sum == l) {
              ans.push_back(v);
            } else {
              ++sum;
            }
            if ((int)ans.size() == len) break;
            if (sum == l) {
              ans.push_back(w);
            } else {
              ++sum;
            }
            if ((int)ans.size() == len) break;
          }
          go = true;
        }
      }
    }
    if (ans.size() < len) ans.push_back(0);
    for (int x : ans) cout << x + 1 << ' ';
    cout << '\n';
  }
}