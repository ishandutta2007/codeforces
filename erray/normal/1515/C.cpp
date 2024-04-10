// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, mx;
    cin >> n >> m >> mx;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < m; ++i) {
      pq.emplace(0, i);
    }
                     
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      auto[tot, ind] = pq.top();
      pq.pop();
      ans[i] = ind;
      pq.emplace(tot + a[i], ind);
    }
    cout << "YES\n";
    for (auto e : ans) {
      cout << e + 1 << ' ';
    }
    cout << '\n';
  }
}