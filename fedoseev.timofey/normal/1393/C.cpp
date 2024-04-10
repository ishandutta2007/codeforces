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
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
    }
    int l = 0, r = n;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      vector <int> cnt(n);
      for (int i = 0; i < n; ++i) {
        ++cnt[a[i]];
      }
      set <pair <int, int>> have;
      auto add = [&] (int x) {
        if (cnt[x] > 0) have.insert({cnt[x], x});
      };  
      auto del = [&] (int x) {
        have.erase({cnt[x], x});
      };
      for (int i = 0; i < n; ++i) add(i);
      vector <int> ans(n);
      for (int i = 0; i < n; ++i) {
        if (have.empty()) break;
        int x = have.rbegin()->second;
        del(x);
        --cnt[x];
        ans[i] = x;
        if (i - m >= 0) add(ans[i - m]);
      }
      bool ok = true;
      for (int i = 0; i < n; ++i) ok &= (cnt[i] == 0);
      if (ok) l = m;
      else r = m;
    }
    cout << l << '\n';
  }
}