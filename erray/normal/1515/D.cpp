// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> left, right;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      --x;
      if (i < l) {
        left.push_back(x);      
      } else {
        right.push_back(x);
      }
    }
    if (int(left.size()) < int(right.size())) {
      swap(left, right);
    }
    vector<int> lct(n);
    vector<int> rct(n);
    for (auto e : left) {
      lct[e]++;
    }
    for (auto e : right) {
      rct[e]++;
    }
    priority_queue<pair<int, int>> pq;
    auto Add = [&](int x) {
      if (lct[x] == 0) {
        return;
      }
      pq.emplace(lct[x] - rct[x], x);
    };
    for (int i = 0; i < n; ++i) {
      Add(i);
    }
    int it = (int(left.size()) - int(right.size())) / 2;
    int ans = it;
    while (it--) {
      assert(!pq.empty());
      auto[foo, x] = pq.top();
      pq.pop();
      --lct[x];
      ++rct[x];
      Add(x);
    }
    int add = 0;
    for (int i = 0; i < n; ++i) {
      add += abs(lct[i] - rct[i]);
    }
    cout << ans + add / 2 << '\n';
  }
}