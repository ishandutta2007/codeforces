#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

bool check(vector <int> x, vector <int> y) {
  {
    int a = x[2] - x[1];
    int b = y[2] - y[1];
    int c = x[0] - x[1];
    int d = y[0] - y[1];
    if (a * c + b * d) {
      swap(x[2], x[1]);
      swap(y[2], y[1]);
    }
  }
  for (int i = 0; i < 4; i++)
    for (int j = i + 1; j < 4; j++)
      if (x[i] == x[j] && y[i] == y[j])
        return false;
  {
    int a = x[2] - x[1];
    int b = y[2] - y[1];
    int c = x[0] - x[1];
    int d = y[0] - y[1];
    if (a * c + b * d) {
      swap(x[0], x[1]);
      swap(y[0], y[1]);
    }
  }
  x.push_back(x[0]);
  x.push_back(x[1]);
  y.push_back(y[0]);
  y.push_back(y[1]);
  if ((x[0] - x[1]) * (x[0] - x[1]) + (y[0] - y[1]) * (y[0] - y[1]) != (x[2] - x[1]) * (x[2] - x[1]) + (y[2] - y[1]) * (y[2] - y[1]))
    return false;
  int sig1 = (x[2] - x[1]) * (y[0] - y[1]) - (y[2] - y[1]) * (x[0] - x[1]);
  int sig2 = (x[3] - x[1]) * (y[0] - y[1]) - (y[3] - y[1]) * (x[0] - x[1]);
  if ((sig1 > 0 && sig2 < 0) || (sig1 < 0 && sig2 > 0))
    return false;
  for (int i = 1; i <= 4; i++) {
    int a = x[i + 1] - x[i];
    int b = y[i + 1] - y[i];
    int c = x[i - 1] - x[i];
    int d = y[i - 1] - y[i];
    if (a * c + b * d)
      return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    vector <int> x(4), y(4), a(4), b(4);
    for (int i = 0; i < 4; i++)
      cin >> x[i] >> y[i] >> a[i] >> b[i];
    int ans = INF;
    for (int it1 = 0; it1 < 4; it1++)
      for (int it2 = 0; it2 < 4; it2++)
        for (int it3 = 0; it3 < 4; it3++)
          for (int it4 = 0; it4 < 4; it4++) {
            vector <int> it = {it1, it2, it3, it4};
            vector <int> newx = x, newy = y;
            int sum = 0;
            for (int i = 0; i < 4; i++) {
              sum += it[i];
              for (int cnt = 0; cnt < it[i]; cnt++) {
                int disx = newx[i] - a[i];
                int disy = newy[i] - b[i];
                newx[i] = a[i] - disy;
                newy[i] = b[i] + disx;
              }
            }
            if (check(newx, newy))
              ans = min(ans, sum);
          }
    if (ans == INF)
      ans = -1;
    cout << ans << '\n';
  }
  return 0;
}