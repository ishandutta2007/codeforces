#include <bits/stdc++.h>
using namespace std;

int n, a[200200];

double eval(double x)
{
  double minS = 0, maxS = 0, s = 0, res = 0;
  for (int i = 0; i < n; i++)
  {
    s += a[i] - x;
    res = max(res, fabs(s - minS));
    res = max(res, fabs(s - maxS));
    minS = min(minS, s);
    maxS = max(maxS, s);
  }
  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];  

  int minA = *min_element(a, a + n);
  int maxA = *max_element(a, a + n);

  double low = minA, high = maxA;
  for (int turn = 0; turn < 100; turn++)
  {
    double mid1 = (low * 2 + high) / 3;
    double mid2 = (low + high * 2) / 3;
    double v1 = eval(mid1);
    double v2 = eval(mid2);
    if (v1 < v2) high = mid2;
    else low = mid1;
  }

  cout << fixed << setprecision(12) << eval(low) << endl;
}