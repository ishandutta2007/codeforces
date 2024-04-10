#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector <set <int>> hor(n), ver(m);
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    hor[x].insert(y);
    ver[y].insert(x);
  }
  for (int i = 0; i < n; i++)
    hor[i].insert(-2), hor[i].insert(1e7);
  for (int i = 0; i < m; i++)
    ver[i].insert(-2), ver[i].insert(1e7);
  int x1, y1, x2, y2;
  x1 = 0, y1 = -1, x2 = n - 1, y2 = m - 1;
  ll sum = k;
  while (sum < n * 1ll * m && x1 <= x2 && y1 <= y2) {
    while (*hor[x1].upper_bound(y1) <= y2)
      y2 = *hor[x1].upper_bound(y1) - 1;
    if (y2 <= y1 && !(y2 == y1 && sum == k + 1))
      break;
    sum += (y2 - y1);
    y1++;
    while (*ver[y2].upper_bound(x1) <= x2)
      x2 = *ver[y2].upper_bound(x1) - 1;
    if (x2 <= x1)
      break;
    sum += (x2 - x1);
    x1++;
    while (*(--hor[x2].lower_bound(y2)) >= y1)
      y1 = *(--hor[x2].lower_bound(y2)) + 1;
    if (y2 <= y1)
      break;
    sum += (y2 - y1);
    y2--;
    while (*(--ver[y1].lower_bound(x2)) >= x1)
      x1 = *(--ver[y1].lower_bound(x2)) + 1;
    if (x2 <= x1)
      break;
    sum += x2 - x1;
    x2--;
  }
  if (sum == n * 1ll * m)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}