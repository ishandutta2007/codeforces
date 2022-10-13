#include <bits/stdc++.h>
using namespace std;
const int N = 300300;

int n, parA[N], parB[N], ans;
int dfsTime, timeIn[N], timeOut[N];
vector<int> a[N], b[N];
set<pair<int, int>> alive;

void visitB(int x)
{
  timeIn[x] = ++dfsTime;
  for (int y : b[x])
    visitB(y);
  timeOut[x] = dfsTime;
}

void visitA(int x)
{
  pair<int, int> removedNode(-1, -1);
  auto it = alive.lower_bound(make_pair(timeIn[x], timeOut[x]));
  int hasDescendant = 0;

  if (it != alive.end()) // check descendant
  {
    if (it->second <= timeOut[x])
      hasDescendant = 1;
  }

  if (!hasDescendant)
  {
    if (it != alive.begin()) // check ancestor
    {
      --it;
      if (it->second >= timeOut[x]) // this is ancestor of x, remove
      {
        removedNode = *it;
        alive.erase(*it);
      }
    }
    alive.insert({timeIn[x], timeOut[x]});
  }

  ans = max(ans, int(alive.size()));

  for (int y : a[x])
    visitA(y);

  if (!hasDescendant)
  {
    alive.erase({timeIn[x], timeOut[x]});
    if (removedNode.first >= 0)
      alive.insert(removedNode);
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
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      a[i].clear();
      b[i].clear();
    }

    for (int i = 1; i < n; i++)
    {
      cin >> parA[i];
      a[--parA[i]].push_back(i);
    }

    for (int i = 1; i < n; i++)
    {
      cin >> parB[i];
      b[--parB[i]].push_back(i);
    }

    dfsTime = 0;
    visitB(0);
    ans = 1;
    alive.clear();
    visitA(0);

    cout << ans << endl;
  }
}