#include <bits/stdc++.h>
using namespace std;

int a[50500][5];

int win(int x, int y)
{
  int cnt = 0;
  for (int i = 0; i < 5; i++)
    cnt += a[x][i] < a[y][i];
  return cnt >= 3;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < 5; j++)
        cin >> a[i][j];

    int ans = 0;
    for (int i = 1; i < n; i++)
      if (win(i, ans))
        ans = i;

    for (int i = 0; i < n; i++)
      if (i != ans && win(i, ans))
      {
        ans = -1;
        break;
      }

    cout << (ans < 0 ? -1 : ans + 1) << '\n';
  }
}