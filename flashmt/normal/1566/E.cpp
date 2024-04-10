#include <bits/stdc++.h>
using namespace std;
const int N = 200200;

int n;
vector<int> a[N], isLeaf, cut;

void process(int x, int par)
{
  int hasLeafChild = 0;
  for (int y : a[x])
    if (y != par)
    {
      process(y, x);
      if (cut[y])
        continue;
      isLeaf[x] = 0;
      if (isLeaf[y])
        hasLeafChild = 1;
    }

  if (x && hasLeafChild)
    cut[x] = 1;
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
      a[i].clear();
    for (int i = 1; i < n; i++)
    {
      int x, y;
      cin >> x >> y;
      a[--x].push_back(--y);
      a[y].push_back(x);
    }

    isLeaf.assign(n, 1);
    cut.assign(n, 0);
    process(0, -1);
    int totalLeaf = accumulate(begin(isLeaf), end(isLeaf), 0);
    int totalCut = accumulate(begin(cut), end(cut), 0);
    cout << totalLeaf - totalCut << '\n';
  }
}