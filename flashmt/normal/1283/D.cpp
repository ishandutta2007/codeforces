#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m, n, x[200200];
  set<int> used;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> x[i];
    used.insert(x[i]);
  }

  sort(x, x + n);
  queue<int> q;
  map<int, int> dist;

  auto push = [&](int i, int curDist)
  {
    if (!used.count(i))
    {
      q.push(i);
      used.insert(i);
      dist[i] = curDist;
    }
  };

  for (int i = 0; i < n;)
  {
    int j = i + 1;
    while (j < n && x[j] == x[i] + 1)
      j++;
    push(x[i] - 1, 1);
    push(x[j - 1] + 1, 1);
    i = j;
  }

  vector<int> ans;
  long long sumDist = 0;
  for (int i = 0; i < m; i++)
  {
    int y = q.front();
    q.pop();
    sumDist += dist[y];
    ans.push_back(y);
    used.insert(y);
    push(y - 1, dist[y] + 1);
    push(y + 1, dist[y] + 1);
  }

  cout << sumDist << endl;
  for (int y : ans)
    cout << y << ' ';
}