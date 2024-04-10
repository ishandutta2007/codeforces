#include <bits/stdc++.h>
using namespace std;
const double oo = 1e15, EPS = 1e-8;;

int n, L, x[1010], b[1010], trace[1010];
double f[1010];

double check(double value)
{
  f[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    f[i] = -oo;
    for (int j = 0; j < i; j++)
    {
      double curF = f[j] + b[i] * value - sqrt(abs(x[i] - x[j] - L));
      if (curF > f[i])
      {
        f[i] = curF;
        trace[i] = j;
      }
    }
  }
  return f[n] > -EPS;
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n >> L;
  for (int i = 1; i <= n; i++) cin >> x[i] >> b[i];
  
  double low = 0, high = oo;
  for (int iteration = 0; iteration < 100; iteration++)
  {
    double mid = (low + high) / 2;
    if (check(mid)) high = mid;
    else low = mid;
  }
  
  vector <int> path;
  for (int x = n; x; x = trace[x]) path.push_back(x);
  for (int i = int(path.size()) - 1; i >= 0; i--) cout << path[i] << ' ';
}