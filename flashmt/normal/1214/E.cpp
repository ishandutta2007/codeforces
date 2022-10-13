#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, chain[200200], x;
  vector<pair<int, int>> d;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    d.push_back({x, i});
  }

  sort(d.begin(), d.end(), greater<pair<int, int>>());

  vector<int> onChain(n * 2, -1), connectTo(n * 2, -1);
  int maxD = d[0].first, firstId = d[0].second;

  chain[0] = firstId * 2;
  onChain[firstId * 2] = 0;

  chain[maxD] = firstId * 2 + 1;
  onChain[firstId * 2 + 1] = maxD;

  int lastChain = maxD, i;

  for (i = 1; i < maxD; i++)
  {
    int curD = d[i].first, id = d[i].second;
    chain[i] = id * 2;
    onChain[id * 2] = i;
    if (i + curD > lastChain)
    {
      chain[++lastChain] = id * 2 + 1;
      onChain[id * 2 + 1] = lastChain;
    }
    else connectTo[id * 2 + 1] = i + curD - 1;
  }

  vector<pair<int, int>> ans;
  for (int i = 0; i < lastChain; i++)
    ans.push_back({chain[i], chain[i + 1]});
  for (int i = 0; i < n * 2; i++)
    if (connectTo[i] >= 0)
      ans.push_back({i, chain[connectTo[i]]});

  for (int i = maxD; i < n; i++)
  {
    int curD = d[i].first, id = d[i].second;
    ans.push_back({chain[0], id * 2});
    if (curD == 1) ans.push_back({id * 2, id * 2 + 1});
    else ans.push_back({id * 2 + 1, chain[curD - 2]});
  }

  for (auto u : ans)
    cout << u.first + 1 << ' ' << u.second + 1 << '\n';
}