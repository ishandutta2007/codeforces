// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q, a0, c0;
  cin >> q >> a0 >> c0;
  const int LG = __lg(q + 1) + 1;
  vector<vector<int>> lift(LG, vector<int>(q + 1));
  auto Up = [&](int v, int x) {
    for (int i = 0; x > 0; ++i, x >>= 1) {
      if (x & 1) {
        v = lift[i][v];
      }
    }
    return v;
  };

  vector<bool> act(q + 1);
  vector<int> a(q + 1);
  vector<int> c(q + 1);
  a[0] = a0;
  c[0] = c0;
  for (int i = 1; i <= q; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      int p, _a, _c;
      cin >> p >> _a >> _c;
      a[i] = _a;
      c[i] = _c;
      lift[0][i] = p;
      for (int j = 1; j < LG; ++j) {
        lift[j][i] = lift[j - 1][lift[j - 1][i]];
      }
    } else {
      int v, w;
      cin >> v >> w;
      int start_v = v;
      int gone = 0;
      for (int j = LG - 1; j >= 0; --j) {
        int next = lift[j][start_v];
        if (a[next] > 0) {
          start_v = next;
          gone += (1 << j);
        } 
      } 
      
      long long taken = 0;
      long long ans = 0;
      while (w > 0 && gone >= 0) {
        int cur = Up(v, gone);
        int take = min(a[cur], w);
        w -= take;
        a[cur] -= take;
        taken += take;
        ans += 1LL * take * c[cur];
        --gone;
      }
      cout << taken << ' ' << ans << endl;
    }
  }
}