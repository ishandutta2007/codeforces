#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    int n, cntX[3] = {0}, cntO[3] = {0};
    string a[333];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
      for (int j = 0; j < n; j++)
        if (a[i][j] == 'X') cntX[(i + j) % 3]++;
        else if (a[i][j] == 'O') cntO[(i + j) % 3]++;
    }

    int bestX = 0, bestO = 1;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        if (i != j && cntX[i] + cntO[j] < cntX[bestX] + cntO[bestO])
        {
          bestX = i;
          bestO = j;
        }

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (a[i][j] == 'X' && (i + j) % 3 == bestX) a[i][j] = 'O';
        else if (a[i][j] == 'O' && (i + j) % 3 == bestO) a[i][j] = 'X';

    for (int i = 0; i < n; i++)
      cout << a[i] << '\n';
  }
}