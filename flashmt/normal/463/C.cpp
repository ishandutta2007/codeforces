#include <bits/stdc++.h>
using namespace std;

int n, a[2020][2020];
long long diagonal1[4040], diagonal2[4040];

int main()
{
  ios::sync_with_stdio(0);
  
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
      cin >> a[i][j];
      diagonal1[i + j] += a[i][j];
      diagonal2[i - j + n] += a[i][j];
    }
      
  long long bestValues[2] = {-1, -1};
  pair <int,int> bestCells[2];
  
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
      int parity = (i + j) % 2;
      long long value = diagonal1[i + j] + diagonal2[i - j + n] - a[i][j];
      if (value > bestValues[parity])
      {
        bestValues[parity] = value;
        bestCells[parity] = make_pair(i, j);
      }
    }
      
  cout << bestValues[0] + bestValues[1] << endl;
  cout << bestCells[0].first << ' ' << bestCells[0].second << ' ';
  cout << bestCells[1].first << ' ' << bestCells[1].second << endl;
}