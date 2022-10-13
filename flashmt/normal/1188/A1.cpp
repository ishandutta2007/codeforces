#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, deg[100100] = {0}, x, y;
  cin >> n;
  for (int i = 1; i < n; i++)
  {
    cin >> x >> y;
    deg[x]++;
    deg[y]++;
  }

  int ans = 1;
  for (int i = 1; i <= n; i++)
    if (deg[i] == 2)
      ans = 0;

  cout << (ans ? "YES" : "NO") << endl;
}