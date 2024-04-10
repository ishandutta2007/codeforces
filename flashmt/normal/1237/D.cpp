#include <bits/stdc++.h>
using namespace std;

int n, a[300300], maxVal[300300][20], lg2[1 << 20];
vector<int> l[300300], r[300300];

void init()
{
  for (int i = 0; i < n * 3; i++)
    maxVal[i][0] = a[i];

  for (int j = 0; j < 18; j++)
    for (int i = 0; i + (1 << j + 1) <= n * 3; i++)
      maxVal[i][j + 1] = max(maxVal[i][j], maxVal[i + (1 << j)][j]);

  for (int j = 0; j < 20; j++)
    for (int i = 1 << j; i < 1 << j + 1; i++)
      lg2[i] = j;
}

int getMax(int l, int r)
{
  int curLg2 = lg2[r - l + 1];
  return max(maxVal[l][curLg2], maxVal[r - (1 << curLg2) + 1][curLg2]);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i + n] = a[i + n * 2] = a[i];
  }

  if (*min_element(a, a + n) * 2 >= *max_element(a, a + n))
  {
    for (int i = 0; i < n; i++)
      cout << -1 << ' ';
    return 0;
  }

  init();

  for (int i = n * 2; i < n * 3; i++)
  {
    int low = i - n + 1, high = i - 1, id = i - n;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (getMax(mid, i - 1) > a[i] * 2)
      {
        id = mid;
        low = mid + 1;
      }
      else high = mid - 1;
    }

    if (id > i - n)
    {
      l[id - n + 1].push_back(i);
      r[id].push_back(i);
    }
  }

  map<int, int> cnt;
  vector<int> ans(n, n * 2);
  for (int i = 0; i < n * 3; i++)
  {
    for (int v : l[i])
      cnt[v]++;

    if (!cnt.empty())
      ans[i % n] = min(ans[i % n], cnt.begin()->first - i);

    for (int v : r[i])
    {
      cnt[v]--;
      if (!cnt[v])
        cnt.erase(v);
    }
  }

  for (int i = 0; i < n; i++)
    cout << ans[i] << " \n"[i == n - 1];
}