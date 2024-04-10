#include <bits/stdc++.h>
using namespace std;

int n, par[100100], type[100100], depth[100100], numObject[100100];
int dfsTime, timeIn[100100], timeOut[100100];
int lowestParentPart[100100], lowestParentObject[100100];
vector <int> a[100100];

void visit(int x)
{
  timeIn[x] = dfsTime++;
  for (int y : a[x])
  {
    depth[y] = depth[x] + 1;
    numObject[y] = numObject[x] + 1 - type[y];
    visit(y);
  }
  timeOut[x] = dfsTime++;
}

int get(int x, int d[])
{
  return d[x] == x ? x : d[x] = get(d[x], d);
}

int isChildren(int x, int y)
{
  return timeIn[y] <= timeIn[x] && timeOut[x] <= timeOut[y];
}

int isSubObject(int x, int y)
{
  return isChildren(x, y) && depth[x] - depth[y] == numObject[x] - numObject[y];
}

int isSubPart(int x, int y)
{
  return isChildren(x, y) && numObject[x] == numObject[y];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> par[i] >> type[i];
    a[max(0, par[i])].push_back(i);
    lowestParentObject[i] = !type[i] ? par[i] : i;
    lowestParentPart[i] = type[i] == 1 ? par[i] : i;
  }

  visit(0);

  int q, t, x, y;
  cin >> q;
  while (q--)
  {
    cin >> t >> x >> y;
    string ans = "NO";
    if (t == 1)
    {
      if (isSubObject(y, x) && x != y)
        ans = "YES";
    }
    else
    {
      int parentObject = get(x, lowestParentObject);
      int parentPart = get(y, lowestParentPart);
      if (isSubObject(x, parentPart) && parentPart != y || isSubPart(y, parentObject) && parentObject != y)
        ans = "YES";
    }
    cout << ans << '\n';
  }
}