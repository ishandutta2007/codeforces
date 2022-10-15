// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<int, int> ct;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++ct[x];
  }

  priority_queue<pair<int, int>> pq;
  for (auto[key, w] : ct) {
    pq.emplace(w, key);
  }
  
  vector<array<int, 3>> ans;
  while ((int) pq.size() > 2) {
    vector<pair<int, int>> tmp(3);
    for (int i = 0; i < 3; ++i) {
      tmp[i] = pq.top(); 
      pq.pop();
    }

    ans.push_back({tmp[0].second, tmp[1].second, tmp[2].second});
    for (auto[freq, e] : tmp) {
      if (freq > 1) {
        pq.emplace(freq - 1, e);
      }
    }
  }

  cout << (int) ans.size() << '\n';
  for (auto e : ans) {
    sort(e.rbegin(), e.rend());
    for (auto e2 : e) {
      cout << e2 << ' ';
    }

    cout << '\n';
  }
}