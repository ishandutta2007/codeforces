#include <iostream>
#include <vector>
#include <iomanip>

#define fsp(x) fixed << setprecision(x)

typedef long double ld;

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, l;
    cin >> n >> l;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    ld v1 = 1, v2 = 1;
    ld t1 = 0, t2 = 0;
    ld x1 = 0, x2 = l;
    ld pos1 = 0, pos2 = n - 1;
    while (pos1 <= pos2) {
      ld newt1 = t1 + (a[pos1] - x1) / v1;
      ld newt2 = t2 + (x2 - a[pos2]) / v2;
      if (newt1 < newt2) {
        t1 = newt1;
        x1 = a[pos1];
        v1 += 1;
        pos1++;
      } else {
        t2 = newt2;
        x2 = a[pos2];
        v2 += 1;
        pos2--;
      }
    }
    ld dis = x2 - x1;
    if (t1 <= t2)
      dis -= (t2 - t1) * v1;
    else
      dis -= (t1 - t2) * v2;
    ld t = max(t1, t2) + dis / (v1 + v2);
    cout << fsp(7) << t << '\n';
  }
  return 0;
}