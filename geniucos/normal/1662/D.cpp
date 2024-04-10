#include <bits/stdc++.h>

#define sz(x) ((int) (x).size())
typedef long long ll;
typedef long double ld;

using namespace std;

int t;
string u, v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> t;
  while (t--) {
    cin >> u >> v;
    int ub = 0, vb = 0;
    string cu, cv;
    for (int i = 0; i < sz(u); i++) {
      if (u[i] == 'B')
        ub++;
      else if (sz(cu) > 0 && cu.back() == u[i])
        cu.pop_back();
      else
        cu.push_back(u[i]);
    }
    for (int i = 0; i < sz(v); i++) {
      if (v[i] == 'B')
        vb++;
      else if (sz(cv) > 0 && cv.back() == v[i])
        cv.pop_back();
      else
        cv.push_back(v[i]);
    }
    cout << (ub % 2 == vb % 2 && cu == cv ? "YES\n" : "NO\n");
  }
}