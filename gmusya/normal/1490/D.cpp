#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> p, d;

void solve(int l, int r, int dep) {
  if (l > r)
    return;
  int id = max_element(p.begin() + l, p.begin() + r + 1) - p.begin();
  d[id] = dep;
  solve(l, id - 1, dep + 1);
  solve(id + 1, r, dep + 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    p.assign(n, 0);
    d.assign(n, 0);
    for (int i = 0; i < n; i++)
      cin >> p[i];
    solve(0, n - 1, 0);
    for (int i = 0; i < n; i++)
      cout << d[i] << ' ';
    cout << '\n';
  }
  return 0;
}