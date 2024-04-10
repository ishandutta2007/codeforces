#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int n;
long long b[100100];
vector<int> a[100100];
long long ans;

void dfs(int x, int par, int dist, vector<pair<long long, int>> gcdSeq)
{
  for (int i = 0; i < gcdSeq.size(); i++)
    gcdSeq[i].first = __gcd(gcdSeq[i].first, b[x]);
  gcdSeq.push_back({b[x], dist});
  int cur = 0;
  for (int i = 1; i < gcdSeq.size(); i++)
  {
    if (gcdSeq[i].first != gcdSeq[cur].first)
      cur++;
    gcdSeq[cur] = gcdSeq[i];
  }
  gcdSeq.resize(cur + 1);

  for (int i = int(gcdSeq.size()) - 2; i >= 0; i--)
    ans = (ans + gcdSeq[i + 1].first * (gcdSeq[i + 1].second - gcdSeq[i].second)) % BASE;
  ans = (ans + gcdSeq[0].first * gcdSeq[0].second) % BASE;

  for (int y : a[x])
    if (y != par)
      dfs(y, x, dist + 1, gcdSeq);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> b[i];
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  dfs(1, 0, 1, {});
  cout << ans << endl;
}