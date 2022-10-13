#include <bits/stdc++.h>
using namespace std;

int n, dist[2222][2222], lab[2222], d[2222][2222];
pair < int, pair <int,int> > edges[2000200];
vector <int> a[2222], c[2222];

int get(int x)
{
  return x == lab[x] ? x : lab[x] = get(lab[x]);
}

void visit(int x, int par, int from)
{
  for (int i = 0; i < int(a[x].size()); i++)
  {
    int y = a[x][i];
    if (y == par) continue;
    d[from][y] = d[from][x] + c[x][i];
    visit(y, x, from);
  }
}

int main()
{
  int numEdge = 0;
  
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
      scanf("%d", dist[i] + j);
      if (i != j && !dist[i][j])
      {
        cout << "NO" << endl;
        return 0;
      }
      if (i < j) edges[numEdge++] = make_pair(dist[i][j], make_pair(i, j));
    }
    
  sort(edges, edges + numEdge);
  for (int i = 1; i <= n; i++) lab[i] = i;
  
  for (int i = 0; i < numEdge; i++)
  {
    int x = edges[i].second.first, y = edges[i].second.second;
    int lx = get(x), ly = get(y);
    if (lx == ly) continue;
    lab[lx] = ly;
    a[x].push_back(y);
    a[y].push_back(x);
    c[x].push_back(edges[i].first);
    c[y].push_back(edges[i].first);
  }
  
  for (int i = 1; i <= n; i++) visit(i, 0, i);
  
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (dist[i][j] != d[i][j])
      {
        cout << "NO" << endl;
        return 0;
      }
      
  cout << "YES" << endl;
}