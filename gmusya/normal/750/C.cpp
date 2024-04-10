#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> c(n), d(n);
  for (int i = 0; i < n; i++)
    cin >> c[i] >> d[i];
  int L = -INF, R = INF;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (d[i] == 1)
      L = max(L, 1900 - sum);
    else
      R = min(R, 1899 - sum);
    sum += c[i];
  }
  if (L > R) {
    cout << "Impossible\n";
    return 0;
  }
  if (R == INF)
    cout << "Infinity\n";
  else
    cout << R + sum;
  return 0;
}