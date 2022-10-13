#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1), oo = 1e12;

int n, m, r[200200][20];
pair<double, double> p[200200];

int isGood(double res)
{
  vector<pair<double, double>> ranges;
  for (int i = 0; i < n; i++)
  {
    double angle = acos(res / p[i].second);
    double alpha = p[i].first - angle, beta = p[i].first + angle;
    if (alpha < 0)
    {
      alpha += PI * 2;
      beta += PI * 2;
    }
    ranges.push_back({alpha, beta});
  }

  sort(ranges.begin(), ranges.end());
  for (int i = 0; i < n; i++)
    ranges.push_back({ranges[i].first + PI * 2, ranges[i].second + PI * 2});

  for (int i = 2 * n - 2; i >= 0; i--)
    ranges[i].second = min(ranges[i].second, ranges[i + 1]. second);

  for (int i = 0; i < n * 2; i++)
    r[i][0] = upper_bound(ranges.begin(), ranges.end(), make_pair(ranges[i].second, oo)) - ranges.begin();
  r[n * 2][0] = n * 2;

  for (int j = 0; j < 17; j++)
    for (int i = 0; i <= n * 2; i++)
      r[i][j + 1] = r[r[i][j]][j];

  for (int i = 0; i < n; i++)
  {
    int x = i;
    for (int j = 17; j >= 0; j--)
      if (m >> j & 1)
      {
        x = r[x][j];
        if (x >= i + n)
          return 1;
      }
  }

  return 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  double minDist = oo;
  int x, y;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> x >> y;
    p[i] = {atan2(y, x), sqrt(1. * x * x + 1. * y * y)};
    minDist = min(minDist, p[i].second);
  }

  double low = 0, high = minDist;
  for (int turn = 0; turn < 60; turn++)
  {
    double mid = (low + high) / 2;
    if (isGood(mid)) low = mid;
    else high = mid;
  }
  cout << fixed << setprecision(9) << low << endl;
}