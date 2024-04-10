#include <bits/stdc++.h>
using namespace std;

int n, d[2020][2020];

void ask(int x)
{
  cout << "? " << x + 1 << endl;
  cout.flush();
  for (int i = 0; i < n; i++)
  {
    cin >> d[x][i];
    d[i][x] = d[x][i];
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  ask(0);
  int cnt[2] = {0};
  for (int i = 1; i < n; i++)
    cnt[d[0][i] % 2]++;

  int toAsk = cnt[0] <= cnt[1] ? 0 : 1;
  for (int i = 1; i < n; i++)
    if (d[i][0] % 2 == toAsk)
      ask(i);

  cout << "!" << endl;
  for (int x = 0; x < n; x++)
    for (int y = x + 1; y < n; y++)
      if (d[x][y] == 1)
        cout << x + 1 << ' ' << y + 1 << endl;
  cout.flush();
}