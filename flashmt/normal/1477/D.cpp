#include <bits/stdc++.h>
using namespace std;

int n, m, ans[2][500500], compId[500500], compSz[500500], isCenter[500500], center[500500];
set<int> a[500500];

void setComp(int x, int comp)
{
  compId[x] = comp;
  compSz[comp]++;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
      a[i].clear();
      compId[i] = -1;
      compSz[i] = isCenter[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
      int x, y;
      cin >> x >> y;
      a[--x].insert(--y);
      a[y].insert(x);
    }

    int label = 0, numComp = 0;
    // find complement components
    for (int i = 0; i < n; i++)
      if (compId[i] == -1)
      {
        vector<int> unseenNeighbors;
        int seenNeighbor = -1;
        for (int j = 0; j < n; j++)
          if (j != i && !a[i].count(j))
          {
            if (compId[j] >= 0) seenNeighbor = j;
            else unseenNeighbors.push_back(j);
          }

        if (!unseenNeighbors.empty())
        {
          isCenter[i] = 1;
          center[numComp] = i;
          setComp(i, numComp);
          for (int j : unseenNeighbors)
            setComp(j, numComp);
          numComp++;
        }
        else if (seenNeighbor < 0)
        {
          compId[i] = -1;
          ans[0][i] = ans[1][i] = label++;
        }
        else if (isCenter[seenNeighbor])
        {
          setComp(i, compId[seenNeighbor]);
        }
        else if (compSz[compId[seenNeighbor]] == 2)
        {
          int curComp = compId[seenNeighbor];
          isCenter[center[curComp]] = 0;
          center[curComp] = seenNeighbor;
          isCenter[seenNeighbor] = 1;
          setComp(i, curComp);
        }
        else
        {
          isCenter[i] = 1;
          center[numComp] = i;
          setComp(i, numComp);
          compSz[compId[seenNeighbor]]--;
          setComp(seenNeighbor, numComp);
          numComp++;
        }
      }

    vector<vector<int>> comps(numComp, vector<int>());
    for (int i = 0; i < n; i++)
      if (compId[i] >= 0)
        comps[compId[i]].push_back(i);

    // assign labels for components
    for (int i = 0; i < numComp; i++)
    {
      assert(compSz[i] > 1);
      for (int j = 1; j < compSz[i]; j++)
        if (isCenter[comps[i][j]])
        {
          swap(comps[i][0], comps[i][j]);
          break;
        }

      for (int j = 0; j < compSz[i]; j++)
      {
        ans[0][comps[i][j]] = label + j;
        ans[1][comps[i][j]] = label + j - 1;
      }
      ans[1][comps[i][0]] = label + compSz[i] - 1;
      label += compSz[i];
    }

    for (int i = 0; i < 2; i++)
      for (int j = 0; j < n; j++)
        cout << ans[i][j] + 1 << " \n"[j == n - 1];
  }
}