#include <bits/stdc++.h>
using namespace std;

int main()
{
  int m, n, cnt = 0, sumX = 0, sumY = 0;
  cin >> m >> n;
  for (int i = 0; i < m; i++)
  {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++)
      if (s[j] == 'B')
      {
        cnt++;
        sumX += i;
        sumY += j;
      }
  }

  cout << sumX / cnt + 1 << ' ' << sumY / cnt + 1 << endl;
}