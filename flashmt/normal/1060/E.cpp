#include <bits/stdc++.h>
using namespace std;

int n, cntParity[200200][2];
vector<int> a[200200];
long long sumDistAll, cntOddDistPair;

pair<int, long long> dfs(int x, int par)
{
  int cnt = cntParity[x][0] = 1;
  long long sumDist = 0;
  for (int y : a[x])
    if (y != par)
    {
      auto [cntY, sumDistY] = dfs(y, x);
      sumDistY += cntY;
      sumDistAll += sumDist * cntY + sumDistY * cnt;
      cnt += cntY;
      sumDist += sumDistY;

      for (int i = 0; i < 2; i++)
        cntOddDistPair += 1LL * cntParity[x][i] * cntParity[y][i];
      for (int i = 0; i < 2; i++)
        cntParity[x][i] += cntParity[y][i ^ 1];
    }
  return {cnt, sumDist};
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }

  dfs(1, 0);
  cout << (sumDistAll + cntOddDistPair) / 2 << endl;
}