#include <bits/stdc++.h>
using namespace std;

int n, hasEdge[3030][3030], cnt[3030][3030];
vector <int> a[3030], aRev[3030];

int main()
{
  ios::sync_with_stdio(0);
  int m, x, y;
  cin >> n >> m;
  while (m--)
  {
    cin >> x >> y;
    a[x].push_back(y);
    hasEdge[x][y] = 1;
    aRev[y].push_back(x);
  }
  
  for (int x = 1; x <= n; x++)
    for (int i = 0; i < int(aRev[x].size()); i++)
      for (int j = i + 1; j < int(aRev[x].size()); j++)
        cnt[aRev[x][i]][aRev[x][j]]++;
        
  long long ans = 0;
  for (int x = 1; x <= n; x++)
    for (int i = 0; i < int(a[x].size()); i++)
      for (int j = i + 1; j < int(a[x].size()); j++)
      {
        int y = a[x][i], z = a[x][j];
        ans += cnt[y][z] + cnt[z][y];
        if (hasEdge[y][x] && hasEdge[z][x]) ans--;
      }
      
  cout << ans << endl;
}