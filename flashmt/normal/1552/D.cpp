#include <bits/stdc++.h>
using namespace std;

int n, a[10], b[10], sz, found, has[1000100];

void go(int i)
{
  if (sz > n)
    return;

  if (i == n)
  {
    found = 1;
    return;
  }

  if (!a[i])
  {
    go(i + 1);
    return;
  }

  for (int j = 0; j < sz; j++)
  {
    int x = b[j] + a[i], added = 0;
    if (!has[x])
    {
      added = 1;
      has[x] = 1;
      b[sz++] = x;
    }
    go(i + 1);
    if (added)
    {
      has[x] = 0;
      sz--;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      a[i] = abs(a[i]);
    }
    sort(a, a + n);
    sz = 1;
    found = 0;
    go(0);

    cout << (found ? "YES\n" : "NO\n");
  }
}