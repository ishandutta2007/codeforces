#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

int q, safeCols[200200];
pair<int, int> treasures[200200];
long long f[200200];

void update(int old, int l, int r)
{
  int oldX = treasures[old].second;
  int colId = lower_bound(safeCols, safeCols + q, oldX) - safeCols;
  int up = treasures[l].first - treasures[old].first;
  if (colId < q)
  {
    int x = safeCols[colId];
    int hor = x - oldX + treasures[r].second - treasures[l].second;
    f[l] = min(f[l], f[old] + up + hor + abs(x - treasures[r].second));
    f[r] = min(f[r], f[old] + up + hor + abs(x - treasures[l].second));
  }

  colId--;
  if (colId >= 0)
  {
    int x = safeCols[colId];
    int hor = oldX - x + treasures[r].second - treasures[l].second;
    f[l] = min(f[l], f[old] + up + hor + abs(x - treasures[r].second));
    f[r] = min(f[r], f[old] + up + hor + abs(x - treasures[l].second));
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;

  cin >> m >> n >> k >> q;
  for (int i = 0; i < k; i++)
    cin >> treasures[i].first >> treasures[i].second;
  for (int i = 0; i < q; i++)
    cin >> safeCols[i];

  treasures[k++] = {1, 1};
  sort(treasures, treasures + k);
  sort(safeCols, safeCols + q);

  int prevL = 0, prevR = 0, i = 1;
  while (i < k && treasures[i].first == 1)
  {
    f[i] = treasures[i].second - 1;
    prevR = i++;
  }
  f[0] = 2 * (treasures[i - 1].second - 1);

  while (i < k)
  {
    int ii = i + 1;
    while (ii < k && treasures[ii].first == treasures[i].first)
      ii++;
    f[i] = f[ii - 1] = oo;
    update(prevL, i, ii - 1);
    update(prevR, i, ii - 1);
    prevL = i;
    prevR = ii - 1;
    i = ii;
  }

  cout << min(f[prevL], f[prevR]) << endl;
}