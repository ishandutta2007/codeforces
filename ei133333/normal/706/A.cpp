#include <bits/stdc++.h>

using namespace std;

#define SQR(x) ((x) * (x))
int main()
{
  int a, b, n;

  cin >> a >> b;
  cin >> n;

  double ret = 1e9;
  while(n--) {
    int x, y, v;
    cin >> x >> y >> v;
    ret = min(ret, sqrt(SQR(a - x) + SQR(b - y)) / v);
  }
  cout << fixed << setprecision(10) << ret << endl;
}