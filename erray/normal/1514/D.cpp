// author: erray
#include <bits/stdc++.h>
 
using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  vector<vector<int>> pos(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
    pos[a[i]].push_back(i);
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    int size = (r - l + 1);
    auto Count = [&](int x) {
      return int(lower_bound(pos[x].begin(), pos[x].end(), r + 1) - lower_bound(pos[x].begin(), pos[x].end(), l));  
    };

    int take = -1;
    for (int it = 0; it < 30; ++it) {
      int ind = uniform_int_distribution<int>(l, r)(rng);
      if (Count(a[ind]) > (size + 1) / 2) {
        take = a[ind];
        break;
      } 
    }
    if (take == -1) {
      cout << 1 << '\n';
    } else {
      int big = Count(take);
      int small = size - big;
      cout << big - small << '\n';
    }
  }
}