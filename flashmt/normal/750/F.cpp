#include <bits/stdc++.h>
using namespace std;

int root;
vector<int> a[1 << 8], asked;

void ask(int x)
{
  asked.push_back(x);
  assert(size(asked) <= 16);

  vector<int> resp;
  cout << "? " << x + 1 << endl;
  cout.flush();
  int k;
  cin >> k;
  if (k == 2)
    root = x;
  while (k--)
  {
    int y;
    cin >> y;
    a[x].push_back(--y);
  }
}

void goToLeaf(int x, vector<int> &path)
{
  path.push_back(x);
  ask(x);
  if (root >= 0)
    return;

  for (int y : a[x])
    if (empty(a[y]))
    {
      goToLeaf(y, path);
      break;
    }
}

void brute(int x, int id, int goal)
{
  if (root >= 0)
    return;

  if (id >= goal)
  {
    if (id == goal)
      root = x;
    return;
  }

  ask(x);
  int child = 0;
  for (int y : a[x])
    if (empty(a[y]))
    {
      brute(y, id * 2 + child, goal);
      child++;
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
    int h;
    cin >> h;

    for (int i = 0; i < 1 << h; i++)
      a[i].clear();
    asked.clear();
    root = -1;

    // find a path connecting 2 leaves
    int start = 0;
    ask(start);
    vector<int> path = {start};
    goToLeaf(a[start][0], path);
    int cur = -1, depth = -1;
    if (size(a[start]) >= 2)
    {
      vector<int> otherPath;
      goToLeaf(a[start][1], otherPath);
      reverse(begin(path), end(path));
      for (int x : otherPath)
        path.push_back(x);
    }

    // move up till depth < 3
    while (root < 0)
    {
      int len = size(path);
      cur = path[len / 2];
      depth = h - 1 - len / 2;
      path.resize(len / 2 + 1);

      if (root >= 0)
        break;

      for (int x : a[cur])
        if (empty(a[x]))
        {
          cur = x;
          depth--;
          break;
        }

      if (depth < 3)
        break;

      goToLeaf(cur, path);
    }

    if (!depth) root = cur;
    else brute(cur, 1, (1 << depth + 1) - 1); // query all but one

    cout << "! " << root + 1 << endl;
    cout.flush();
  }
}