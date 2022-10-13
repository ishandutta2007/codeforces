#include <bits/stdc++.h>
using namespace std;

int n, a[300300], f[300300], prevValue[300300];
vector<int> id[300300];

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
      id[a[i]].push_back(i);
    }
    int last = 0, numValues = 0;
    for (int i = 1; i <= n; i++)
      if (!id[i].empty())
      {
        prevValue[i] = last;
        last = i;
        numValues++;
      }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
      int v = a[i];
      if (id[v][0] == i)
      {
        int u = prevValue[v];
        if (u && i > id[u].back()) f[v] = f[u] + 1;
        else f[v] = 1;
        ans = max(ans, f[v]);
      }
    }

    cout << numValues - ans << '\n';

    for (int i = 0; i < n; i++)
    {
      id[a[i]].clear();
      prevValue[a[i]] = 0;
    }
  }
}