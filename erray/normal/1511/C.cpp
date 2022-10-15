// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }

  
  vector<bool> vis(50);
  vector<pair<int, int>> p;
  for (int i = 0; i < n; ++i) {
    if (!vis[a[i]]) {
      p.emplace_back(i, a[i]);
    }
    vis[a[i]] = true;
  }
  n = (int) p.size();

  vector<int> add(50);
  while (q--) {
    int x;
    cin >> x;
    --x;
    int ind = -1;
    for (int i = 0; i < n; ++i) {
      if (p[i].second == x) {
        ind = i;
      } else {
        p[i].first += (ind == -1);
      }
    }
    cout << p[ind].first + 1 << ' ';
    p.erase(p.begin() + ind);
    p.insert(p.begin(), {0, x});
  }

}