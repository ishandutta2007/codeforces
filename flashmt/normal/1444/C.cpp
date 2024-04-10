#include <bits/stdc++.h>
using namespace std;
const int N = 1000100;

int n, numGroup, numColor, color[N], idGroup[N], isGoodGroup[N], flag[N], counter, color2[N];
vector<int> sameEdges[N], otherEdges[N], groups[N], newEdges[N];

// DFS in 1 group
int visit(int x)
{
  for (int y : sameEdges[x])
    if (color[y] < 0)
    {
      color[y] = color[x] ^ 1;
      if (!visit(y))
        return 0;
    }
    else if (color[y] == color[x])
      return 0;
  return 1;
}

int checkGoodGroup(int curGroup)
{
  for (int x : groups[curGroup])
    if (color[x] < 0)
    {
      color[x] = numColor;
      if (!visit(x))
        return 0;

      if (!sameEdges[x].empty())
      {
        newEdges[numColor].push_back(numColor + 1);
        newEdges[numColor + 1].push_back(numColor);
      }
      numColor += 2;
    }

  return 1;
}

// DFS in 2 groups
int visit2(int x)
{
  for (int y : newEdges[x])
    if (flag[y] < counter)
    {
      flag[y] = counter;
      color2[y] = color2[x] ^ 1;
      if (!visit2(y))
        return 0;
    }
    else if (color2[y] == color2[x])
      return 0;

  return 1;
}

bool compareEdge(pair<int, int> u, pair<int, int> v)
{
  return idGroup[u.second] < idGroup[v.second];
}

int calcGroup(int group0)
{
  set<int> bad;
  vector<pair<int, int>> edges;
  for (int x : groups[group0])
    for (int y : otherEdges[x])
      edges.push_back({x, y});

  // sort edges by group
  sort(edges.begin(), edges.end(), compareEdge);
  for (int i = 0; i < edges.size();)
  {
    int ii = i, group1 = idGroup[edges[i].second];
    while (ii < edges.size() && idGroup[edges[ii].second] == group1)
      ii++;

    if (isGoodGroup[group1])
    {
      // check odd cycle for group0 and group1
      for (int j = i; j < ii; j++)
      {
        auto [x, y] = edges[j];
        newEdges[color[x]].push_back(color[y]);
        newEdges[color[y]].push_back(color[x]);
      }

      counter++;
      for (int j = i; j < ii; j++)
      {
        int x = color[edges[j].first];
        if (flag[x] < counter)
        {
          flag[x] = counter;
          color2[x] = 0;
          if (!visit2(x))
            bad.insert(group1);
        }
      }

      for (int j = i; j < ii; j++)
      {
        auto [x, y] = edges[j];
        newEdges[color[x]].pop_back();
        newEdges[color[y]].pop_back();
      }
    }

    i = ii;
  }

  return bad.size();
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m;
  cin >> n >> m >> numGroup;
  for (int i = 1; i <= n; i++)
  {
    cin >> idGroup[i];
    groups[idGroup[i]].push_back(i);
  }
  while (m--)
  {
    int x, y;
    cin >> x >> y;
    if (idGroup[x] == idGroup[y])
    {
      sameEdges[x].push_back(y);
      sameEdges[y].push_back(x);
    }
    else
    {
      otherEdges[x].push_back(y);
      otherEdges[y].push_back(x);
    }
  }

  memset(color, -1, sizeof color);
  int numBadGroup = 0;
  for (int i = 1; i <= numGroup; i++)
  {
    isGoodGroup[i] = checkGoodGroup(i);
    numBadGroup += 1 - isGoodGroup[i];
  }

  long long ans = numGroup * (numGroup - 1LL);
  for (int i = 1; i <= numGroup; i++)
    if (isGoodGroup[i]) ans -= calcGroup(i) + numBadGroup;
    else ans -= numGroup - 1;
  cout << ans / 2 << endl;
}