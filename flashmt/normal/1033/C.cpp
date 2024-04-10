#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[100100], id[100100];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    id[a[i]] = i;
  }

  int g[100100] = {0};
  for (int x = n; x; x--)
  {
    int curId = id[x];
    set<int> s;
    for (int i = x; i <= n; i += x)
    {
      int j = curId - i;
      if (j >= 0 && a[j] > x)
        s.insert(g[a[j]]);
      j = curId + i;
      if (j < n && a[j] > x)
        s.insert(g[a[j]]);
    }
    while (s.count(g[x]))
      g[x]++;
  }

  for (int i = 0; i < n; i++)
    cout << (g[a[i]] ? 'A' : 'B');
  cout << endl;
}