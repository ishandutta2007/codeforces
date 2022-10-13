#include <bits/stdc++.h>
using namespace std;

int nextId[1000100], id[1000100], n, flag[1000100];
pair <int,int> a[1000100];

int main()
{
  ios::sync_with_stdio(0);
  int u, v;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i].first >> a[i].second;
    flag[a[i].second] = 1;
    nextId[a[i].first] = a[i].second;
    if (!a[i].first) u = a[i].second;
  }
  
  for (int i = 1; i < n; i += 2)
  {
    id[i] = u;
    u = nextId[u];
  }
  
  for (int i = 0; i < n; i++)
    if (!flag[a[i].first])
    {
      v = a[i].first;
      break;
    }
  
  for (int i = 0; i < n; i += 2)
  {
    id[i] = v;
    v = nextId[v];
  }
  
  for (int i = 0; i < n; i++) cout << id[i] << ' ';
}