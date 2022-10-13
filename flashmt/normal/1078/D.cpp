#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int n, a[300300], l[17][300300], r[17][300300];
int treeL[17][1200200], treeR[17][1200200];

void init(int id, int low, int high, int tree[], int v[])
{
  if (low == high) tree[id] = v[low];
  else
  {
    int mid = (low + high) / 2;
    init(id * 2, low, mid, tree, v);
    init(id * 2 + 1, mid + 1, high, tree, v);
    tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
  }
}

inline int get(int id, int low, int high, int x, int y, int tree[])
{
  if (low == x && high == y)
    return tree[id];
  int u = -oo, v = -oo, mid = (low + high) / 2;
  if (x <= mid)
    u = get(id * 2, low, mid, x, min(y, mid), tree);
  if (mid < y)
    v = get(id * 2 + 1, mid + 1, high, max(x, mid + 1), y, tree);
  return max(u, v);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  if (n == 1)
  {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = n; i < n * 3; i++)
    a[i] = a[i - n];

  for (int i = 0; i < n * 3; i++)
  {
    l[0][i] = -max(0, i - a[i]);
    r[0][i] = min(n * 3 - 1, i + a[i]);
  }

  for (int i = 0; i <= 16; i++)
  {
    init(1, 0, n * 3 - 1, treeL[i], l[i]);
    init(1, 0, n * 3 - 1, treeR[i], r[i]);
    if (i == 16)
      break;

    for (int j = 0; j < n * 3; j++)
    {
      l[i + 1][j] = get(1, 0, n * 3 - 1, -l[i][j], r[i][j], treeL[i]);
      r[i + 1][j] = get(1, 0, n * 3 - 1, -l[i][j], r[i][j], treeR[i]);
    }
  }

  for (int i = 0; i < n; i++)
  {
    int ans = 0, curL = n + i, curR = n + i;
    for (int j = 16; j >= 0; j--)
    {
      int newL = -get(1, 0, n * 3 - 1, curL, curR, treeL[j]);
      int newR = get(1, 0, n * 3 - 1, curL, curR, treeR[j]);
      if (newR - newL + 1 < n)
      {
        ans |= 1 << j;
        curL = newL;
        curR = newR;
      }
    }
    cout << ans + 1 << " \n"[i == n - 1];
  }
}