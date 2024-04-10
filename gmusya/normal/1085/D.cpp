#include <iostream>
#include <vector>
#include <iomanip>

#define fsp(x) fixed << setprecision(x)

using namespace std;

typedef long double ld;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  ld s;
  cin >> n >> s;
  vector <int> deg(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    deg[u]++, deg[v]++;
  }
  int l = 0;
  for (int v = 0; v < n; v++)
    if (deg[v] == 1)
      l++;
  cout << fsp(10) << 2 * s / l;
  return 0;
}