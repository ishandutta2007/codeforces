#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  set<int> s;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    s.insert(i - 1);
  }
  for (int i = 1; i <= n; i++)
    cin >> b[i];

  vector<int> dist(n + 1, -1), tr(n + 1);
  queue<int> q;
  q.push(n);
  dist[n] = 0;
  while (!empty(q))
  {
    int x = q.front();
    q.pop();
    int high = x + b[x], low = high - a[high];
    auto u = s.lower_bound(low);
    while (u != end(s) && *u <= high)
    {
      int y = *u++;
      s.erase(y);
      dist[y] = dist[x] + 1;
      tr[y] = x;
      q.push(y);
    }
  }

  if (dist[0] < 0) cout << -1 << endl;
  else
  {
    cout << dist[0] << endl;
    vector<int> path;
    for (int x = 0; x < n; x = tr[x])
      path.push_back(x);
    reverse(begin(path), end(path));
    for (int x : path)
      cout << x << ' ';
  }
}