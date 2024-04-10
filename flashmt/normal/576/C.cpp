#include <bits/stdc++.h>
using namespace std;

int n, x[1000100], y[1000100], id[1000100];

bool cmp(int u, int v)
{
  int xxu = x[u] / 1000, yyu = y[u] / 1000;
  int xxv = x[v] / 1000, yyv = y[v] / 1000;
  if (xxu != xxv) return xxu < xxv;
  return xxu % 2 ? yyu < yyv : yyu > yyv;
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    scanf("%d%d", x + i, y + i);
    id[i] = i;
  }

  sort(id, id + n, cmp);
  for (int i = 0; i < n; i++)
    printf("%d ", id[i] + 1);
}