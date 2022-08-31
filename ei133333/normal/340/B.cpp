#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
const int INF = 1 << 30;

double cross(double x1, double y1, double x2, double y2)
{
  return(x1 * y2 - y1 * x2);
}

int main()
{
  int N;
  double x[300], y[300];
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
  }
  double ret = 0;
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j < N; j++) {
      double a = 0, b = 0;
      for(int k = 0; k < N; k++) {
        if(i == k || j == k) continue;
        double dist = cross(x[k] - x[i], y[k] - y[i], x[k] - x[j], y[k] - y[j]);
        a = max(a, dist);
        b = min(b, dist);
      }
      if(a > 0 && b < 0) ret = max(ret, a - b);
    }
  }
  cout << fixed << setprecision(20) << ret / 2.0 << endl;
}