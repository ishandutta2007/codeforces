#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int n, a[600600], lg2[1 << 20];
pair<int, int> minVal[600600][20];

void init()
{
  for (int i = 0; i < n * 2; i++)
    a[i + n] = a[i];

  for (int i = 0; i < n * 3; i++)
    minVal[i][0] = {a[i], i};
  for (int j = 0; j < 19; j++)
    for (int i = 0; i + (1 << j + 1) <= n * 3; i++)
      minVal[i][j + 1] = min(minVal[i][j], minVal[i + (1 << j)][j]);

  for (int j = 0; j < 20; j++)
    for (int i = 1 << j; i < 1 << j + 1; i++)
      lg2[i] = j;
}

int getMin(int l, int r)
{
  int curLg2 = lg2[r - l + 1];
  return min(minVal[l][curLg2], minVal[r - (1 << curLg2) + 1][curLg2]).second;
}

int calcDepth(int l, int r)
{
  if (l > r)
    return 0;
  int id = getMin(l, r);
  return max(calcDepth(l, id - 1), calcDepth(id + 1, r)) + 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int id;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i]--;
    if (!a[i])
      id = i;
  }

  init();

  int ans = oo, where;
  int low = id + 1, high = id + n;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    int depthL = calcDepth(mid, id + n - 1);
    int depthR = calcDepth(id + n + 1, mid + n - 1);
    int depth = max(depthL, depthR) + 1;
    if (depth < ans)
    {
      ans = depth;
      where = mid;
    }
    if (depthL > depthR) low = mid + 1;
    else high = mid - 1;
  }

  cout << ans << ' ' << where % n << endl;
}