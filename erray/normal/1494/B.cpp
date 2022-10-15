// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, u, r, d, l;
    cin >> n >> u >> r >> d >> l;
    auto can = [&](int x, int f, int s) {
      return f + s <= x && n - (f ^ 1) - (s ^ 1) >= x;
    };
    
    bool ok = false;
    for (int ul = 0; ul < 2; ++ul) {
      for (int ur = 0; ur < 2; ++ur) {
        for (int dl = 0; dl < 2; ++dl) {
          for (int dr = 0; dr < 2; ++dr) {
            ok |= (can(u, ul, ur) && can(r, ur, dr) && can(l, ul, dl) && can(d, dl, dr));
          }
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}