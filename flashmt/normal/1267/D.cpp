#include <bits/stdc++.h>
using namespace std;

int n, featureMask[256], testMask[256], hasCT[256], deployed[256];
vector<int> servers[8];
vector<pair<int, int>> cdPairs;

void fullDeploy(int s)
{
  queue<int> q;
  q.push(s);
  while (!q.empty())
  {
    int x = q.front();
    q.pop();

    int curMask = hasCT[x] ? testMask[x] : featureMask[x];
    for (int y : servers[curMask])
      if (deployed[y] != curMask)
      {
        deployed[y] = curMask;
        hasCT[y] = 1;
        cdPairs.push_back({x, y});
        q.push(y);
      }
  }
}

int findCombinedDeployment()
{
  for (int mask = 3; mask < 8; mask++)
    if (__builtin_popcount(mask) == 2 && !servers[mask].empty())
    {
      int x = servers[mask][0];
      if (deployed[x] == mask)
        continue;

      vector<int> from;
      for (int i = 0; i < 3; i++)
        if (mask >> i & 1)
          for (int y = 0; y < n; y++)
            if (deployed[y] == featureMask[y])
            {
              int toDeploy = hasCT[y] ? testMask[y] : featureMask[y];
              if (toDeploy == 1 << i)
              {
                from.push_back(y);
                break;
              }
            }

      if (from.size() == 2)
      {
        for (int y : from)
          cdPairs.push_back({y, x});
        deployed[x] = mask;
        return x;
      }
    }

  return -1;
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      int x;
      cin >> x;
      featureMask[i] |= x << j;
    }
    servers[featureMask[i]].push_back(i);
  }

  for (int i = 0; i < n; i++)
    for (int j = 0; j < 3; j++)
    {
      int x;
      cin >> x;
      testMask[i] = (testMask[i] | x << j) & featureMask[i];
    }

  int s = 0;
  deployed[0] = 7;
  hasCT[0] = servers[7].empty();
  while (s >= 0)
  {
    fullDeploy(s);
    s = findCombinedDeployment();
  }

  int isGood = 1;
  for (int i = 1; i < n; i++)
    if (deployed[i] != featureMask[i])
      isGood = 0;

  if (!isGood) cout << "Impossible\n";
  else
  {
    cout << "Possible\n";
    for (int i = 0; i < n; i++)
      cout << hasCT[i] << " \n"[i == n - 1];
    cout << cdPairs.size() << '\n';
    for (auto [x, y] : cdPairs)
      cout << x + 1 << ' ' << y + 1 << '\n';
  }
}