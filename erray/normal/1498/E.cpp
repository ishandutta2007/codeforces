// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> k(n);
  for (int i = 0; i < n; ++i) {
    cin >> k[i];
  }
  vector<pair<int, int>> l;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (k[i] < k[j] || i == j) continue;
      l.emplace_back(i, j);
    }
  }
  sort(l.begin(), l.end(), [&](auto x, auto y) {
    return k[x.first] - k[x.second] > k[y.first] - k[y.second];
  });
  
  auto Ask = [&](int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    string res;
    cin >> res;
    return (res[0] == 'Y');
  };

  for (auto[v, u] : l) {
    ++v, ++u;
    if (Ask(v, u)) {
      cout << "! " << v << ' ' << u << endl;
      exit(0);
    }
  }
  cout << "! 0 0" << endl;
}