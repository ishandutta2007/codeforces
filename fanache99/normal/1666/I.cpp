#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef long double ld;

int t, n, m;

int scan(int r, int c) {
  cout << "SCAN " << r + 1 << " " << c + 1 << endl;
  int q;
  cin >> q;
  return q;
}

int dig(int r, int c) {
  cout << "DIG " << r + 1 << " " << c + 1 << endl;
  int q;
  cin >> q;
  return q;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    int v1 = scan(0, 0);
    int v2 = scan(0, m - 1);
    int xs = (v1 + v2 - 2 * (m - 1)) / 2;
    int ys = v1 - xs;
    int v3 = scan(xs / 2, 0);
    int xd = v3 - ys;
    int x1 = (xs - xd) / 2, x2 = (xs + xd) / 2;
    int v4 = scan(0, ys / 2);
    int yd = v4 - xs;
    int y1 = (ys - yd) / 2, y2 = (ys + yd) / 2;
    if (dig(x1, y1))
      dig(x2, y2);
    else
      dig(x1, y2), dig(x2, y1);
  }
}