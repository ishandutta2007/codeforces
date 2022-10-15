// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int tx, ty;
    cin >> tx >> ty;
    vector<int> c(6);
    for (int i = 0; i < 6; ++i) {
      cin >> c[i];
    }

    for (int i = 0; i < 6; ++i) {
      int prev = (i - 1 + 6) % 6;
      int next = (i + 1) % 6;
      c[i] = min(c[i], c[prev] + c[next]);
    }

    auto cost = [&](int x, int y) {
      return 1LL * abs(y) * c[y < 0 ? 4 : 1] +  1LL * abs(x) * c[x < 0 ? 2 : 5];
    };
      
    cout << min({cost(tx, ty), cost(tx - ty, 0) + 1LL * abs(ty) * c[ty < 0 ? 3 : 0], cost(0, ty - tx) + 1LL * abs(tx) * c[tx < 0 ? 3 : 0]}) << '\n';
  }
}