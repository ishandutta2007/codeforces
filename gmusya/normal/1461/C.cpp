#include <iostream>
#include <vector>
#include <iomanip>

#define fsp(x) fixed << setprecision(x)

using namespace std;

typedef long double ld;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    while (!a.empty() && a.back() == n) {
      n--;
      a.pop_back();
    }
    ld fail = 1;
    while (m--) {
      int r;
      ld p;
      cin >> r >> p;
      r = min(r, n);
      if (r == n)
        fail *= 1 - p;
    }
    if (a.empty()) {
      cout << fsp(7) << 1.0 << '\n';
      continue;
    }
    cout << fsp(7) << 1 - fail << '\n';
  }
  return 0;
}