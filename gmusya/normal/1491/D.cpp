#include <iostream>
#include <vector>

using namespace std;

bool solve(int u, int v) {
  if (u == v)
    return true;
  if (u > v)
    return false;
  if (u == 0)
    return false;
  if (u % 2 == v % 2)
    return solve(u / 2, v / 2);
  if (u % 2 == 0)
    return false;
  int x = 1;
  while ((u & x) == x) {
    if (solve(u + x, v))
      return true;
    x = x * 2 + 1;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    if (solve(u, v))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}