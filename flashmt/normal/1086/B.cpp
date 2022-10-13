#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, s, deg[100100] = {0};
  cin >> n >> s;
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    deg[x]++;
    deg[y]++;
  }

  int leaf = 0;
  for (int i = 1; i <= n; i++)
    leaf += deg[i] == 1;

  cout << fixed << setprecision(9) << 2. * s / leaf << endl;
}