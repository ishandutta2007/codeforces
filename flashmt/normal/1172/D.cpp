#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, r[1010], c[1010], idR[1010], idC[1010];
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> r[i];
    idR[r[i]] = i;
  }
  for (int i = 1; i <= n; i++)
  {
    cin >> c[i];
    idC[c[i]] = i;
  }

  vector<array<int, 4>> portals;
  for (int i = 1; i <= n; i++)
  {
    if (r[i] == i && c[i] == i)
      continue;
    int row = idR[i], col = idC[i];
    portals.push_back({row, i, i, col});
    idR[r[i]] = row;
    swap(r[i], r[row]);
    idC[c[i]] = col;
    swap(c[i], c[col]);
  }

  cout << portals.size() << '\n';
  for (auto p : portals)
    for (int i = 0; i < 4; i++)
      cout << p[i] << " \n"[i == 3];
}