#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  auto ask = [&](vector<pair<double, double>> &poly)
  {
    cout << "? " << size(poly) << endl;
    for (auto [x, y] : poly)
      cout << x << ' ' << y << endl;
    cout.flush();
    double resp;
    cin >> resp;
    return resp;
  };

  vector<pair<double, double>> poly;
  poly.push_back({0, m + 1});
  for (int i = 0; i < n; i++)
  {
    poly.push_back({i, 0});
    poly.push_back({i + 1, m});
  }
  poly.push_back({n, m + 1});
  double ansY = ask(poly) * m - 0.5;

  poly.clear();
  poly.push_back({n + 1, 0});
  for (int i = 0; i < m; i++)
  {
    poly.push_back({0, i});
    poly.push_back({n, i + 1});
  }
  poly.push_back({n + 1, m});
  double ansX = ask(poly) * n - 0.5;

  cout << fixed << setprecision(9) << "! " << ansX << ' ' << ansY << endl;
  cout.flush();
}