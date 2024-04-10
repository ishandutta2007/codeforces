#include <bits/stdc++.h>
using namespace std;

vector<int> a[100100];
int distA[100100], distU[100100];

void visit(int x, int par, int dist[])
{
  for (int y : a[x])
    if (y != par)
    {
      dist[y] = dist[x] + 1;
      visit(y, x, dist);
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
    int n, alice, bob, da, db;
    cin >> n >> alice >> bob >> da >> db;
    for (int i = 1; i <= n; i++)
      a[i].clear();
    for (int i = 1; i < n; i++)
    {
      int x, y;
      cin >> x >> y;
      a[x].push_back(y);
      a[y].push_back(x);
    }

    distA[alice] = 0;
    visit(alice, 0, distA);
    int u = 1;
    for (int i = 2; i <= n; i++)
      if (distA[i] > distA[u])
        u = i;
    distU[u] = 0;
    visit(u, 0, distU);
    int maxDist = *max_element(distU, distU + n + 1);

    da = min(da, maxDist);
    db = min(db, maxDist);

    if (distA[bob] <= da || da * 2 >= db) cout << "Alice\n";
    else cout << "Bob\n";
  }
}