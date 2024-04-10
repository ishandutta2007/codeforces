#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

#define fsp(x) fixed << setprecision(x)

typedef long double ld;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <ld> p(n);
  for (int i = 0; i < n; i++)
    cin >> p[i];
  sort(p.rbegin(), p.rend());
  ld ans = 0;
  ld p0 = 1, p1 = 0;
  for (int i = 0; i < n; i++) {
    ld newp0 = p0 * (1 - p[i]);
    ld newp1 = p0 * p[i] + p1 * (1 - p[i]);
    swap(newp0, p0);
    swap(newp1, p1);
    ans = max(ans, p1);
  }
  cout << fsp(15) << ans;
  return 0;
}