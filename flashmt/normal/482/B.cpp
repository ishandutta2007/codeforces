#include <bits/stdc++.h>
using namespace std;

int n, a[100100], ans[100100];
vector < pair <int,int> > q[33][2];

int solve(int bit)
{
  memset(a, 0, sizeof a);
  for (int i = 0; i < int(q[bit][1].size()); i++)
  {
    a[q[bit][1][i].first]++;
    a[q[bit][1][i].second + 1]--;
  }
  
  for (int i = 1; i <= n; i++) 
  {
    a[i] += a[i - 1];
    if (a[i]) ans[i] |= 1 << bit;
  }
  
  for (int i = 1; i <= n; i++) a[i] = a[i - 1] + (a[i] == 0);
  for (int i = 0; i < int(q[bit][0].size()); i++)
    if (a[q[bit][0][i].second] == a[q[bit][0][i].first - 1])
      return 0;
      
  return 1;
}

int main()
{
  ios::sync_with_stdio(0);
  int m, l, r, x;
  cin >> n >> m;
  while (m--)
  {
    cin >> l >> r >> x;
    for (int bit = 0; bit < 30; bit++)
      q[bit][x >> bit & 1].push_back(make_pair(l, r));
  }
  
  for (int bit = 0; bit < 30; bit++)
    if (!solve(bit))
    {
      cout << "NO" << endl;
      return 0;
    }
    
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}