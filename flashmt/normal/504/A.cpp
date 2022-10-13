#include <bits/stdc++.h>
using namespace std;

int n, deg[100100], s[100100];
queue <int> q;
vector < pair <int,int> > edges;

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) 
  {
    cin >> deg[i] >> s[i];
    if (deg[i] == 1) q.push(i);
  }
  
  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    if (deg[x] < 1) continue;
    
    int y = s[x];
    edges.push_back(make_pair(x, y));
    s[y] ^= x;
    deg[y]--;
    if (deg[y] == 1) q.push(y);
  }
  
  cout << edges.size() << endl;
  for (int i = 0; i < int(edges.size()); i++)
    cout << edges[i].first << ' ' << edges[i].second << endl;
}