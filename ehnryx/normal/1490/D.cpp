#include <bits/stdc++.h>
using namespace std;

constexpr char nl = '\n';

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<pair<int,int>> order;
    for(int i=0; i<n; i++) {
      int a;
      cin >> a;
      order.emplace_back(a, i);
    }
    sort(begin(order), end(order), greater<pair<int,int>>());

    vector<int> d(n);
    map<int,int> seen;
    for(auto [v, i] : order) {
      auto it = seen.insert(pair(i, v)).first;
      int left = n + 1;
      if(it != begin(seen)) {
        left = prev(it)->second;
      }
      int right = n + 1;
      if(next(it) != end(seen)) {
        right = next(it)->second;
      }

      if(left < right) {
        int j = prev(it)->first;
        d[i] = d[j] + 1;
      } else if(right < left) {
        int j = next(it)->first;
        d[i] = d[j] + 1;
      }
    }

    for(int i=0; i<n; i++) {
      cout << d[i] << " ";
    }
    cout << nl;
  }

  return 0;
}