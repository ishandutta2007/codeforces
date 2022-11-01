#include <iostream>
#include <vector>
#include <iomanip>

#define fsp(x) fixed << setprecision(x)

typedef long double ld;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, h;
  cin >> n >> m >> h;
  vector <int> s(m);
  for (int i = 0; i < m; i++)
    cin >> s[i];
  int sum = 0;
  for (int i = 0; i < m; i++)
    sum += s[i];
  if (sum < n) {
    cout << -1;
    return 0;
  }
  ld all = sum;
  ld p = 1;
  for (int i = 1; i < n; i++) {
    p *= (all - s[h - 1]) / (all - 1);
    all--;
  }
  cout << fsp(15) << 1 - p;
  return 0;
}