#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, m;
    cin >> n >> m;
    vector<int> isRoot(n, 1);
    while (m--)
    {
      int x, y, z;
      cin >> x >> y >> z;
      isRoot[--y] = 0;
    }

    int root = 0;
    while (!isRoot[root])
      root++;

    for (int i = 0; i < n; i++)
      if (i != root)
        cout << root + 1 << ' ' << i + 1 << '\n';
  }
}