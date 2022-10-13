#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;
const int oo = 27081993;

vector<int> a[1000100][10];
int n, nextV[1000100][10];

void addEdge(int x, int y, int id)
{
  vector<int> digits;
  while (id)
  {
    digits.push_back(id % 10);
    id /= 10;
  }
  for (int i = digits.size() - 1; i; i--)
  {
    int d = digits[i];
    if (!nextV[x][d])
      nextV[x][d] = ++n;
    a[x][d].push_back(nextV[x][d]);
    x = nextV[x][d];
  }
  a[x][digits[0]].push_back(y);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m, x, y;
  cin >> n >> m;
  int realN = n;
  for (int i = 1; i <= m; i++)
  {
    cin >> x >> y;
    addEdge(x, y, i);
    addEdge(y, x, i);
  }

  vector<int> done(n + 1, 0);
  vector<long long> ans(n + 1, 0);
  queue<int> q;

  q.push(1);
  done[1] = 1;
  while (!q.empty())
  {
    vector<int> candidates;
    candidates.push_back(q.front());
    q.pop();
    long long curAns = ans[candidates[0]];
    while (!q.empty() && ans[q.front()] == curAns)
    {
      candidates.push_back(q.front());
      q.pop();
    }

    for (int d = 0; d < 10; d++)
      for (int x : candidates)
        for (int y : a[x][d])
          if (!done[y])
          {
            done[y] = 1;
            ans[y] = (ans[x] * 10 + d) % BASE;
            q.push(y);
          }
  }

  for (int i = 2; i <= realN; i++)
    cout << ans[i] << '\n';
}