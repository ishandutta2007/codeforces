#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef pair <int, int> pii;
typedef vector <pii> vpii;
typedef vector <vpii> vvpii;

const int MAXN = 5000000;

vvi vhod(MAXN + 1);

void check(pii a, pii b) {
  int x = a.first, y = a.second;
  int z = b.first, w = b.second;
  if (x == z || x == w || y == z || y == w)
    return;
  cout << "YES\n";
  cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << ' ' << w + 1 << '\n';
  exit(0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    vhod[a[i]].push_back(i + 1);
  for (int i = 0; i <= MAXN; i++)
    if (vhod[i].size() >= 4) {
      cout << "YES\n";
      for (int j = 0; j < 4; j++)
        cout << vhod[i][j] << ' ';
      return 0;
    }
  int id0 = -1, id1 = -1;
  for (int i = 0; i <= MAXN; i++)
    if (vhod[i].size() >= 2) {
      if (id0 == -1)
        id0 = i;
      else
        id1 = i;
    }
  if (id1 != -1) {
    cout << "YES\n";
    for (int i = 0; i < 2; i++)
      cout << vhod[id0][i] << ' ' << vhod[id1][i] << ' ';
    return 0;
  }
  vhod = vvi();
  vvpii pairs(2 * MAXN + 1);
  n = min(n, 2000);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      pairs[a[i] + a[j]].push_back({i, j});
  for (int i = 0; i <= 2 * MAXN; i++) {
    for (int j = 0; j < pairs[i].size(); j++)
      for (int k = j + 1; k < pairs[i].size(); k++)
        check(pairs[i][j], pairs[i][k]);
  }
  cout << "NO\n";
  return 0;
}