#include <bits/stdc++.h>
using namespace std;

string solveMax(int m, int s, int isFirstDigit)
{
  if (m == 1) string(1, char(s + '0'));
  for (int i = min(9, s); i >= isFirstDigit; i--)
    if (s - i <= (m - 1) * 9)
      return string(1, char(i + '0')) + solveMax(m - 1, s - i, 0);
  return "";
}

string solveMin(int m, int s, int isFirstDigit)
{
  if (m == 1) string(1, char(s + '0'));
  
  for (int i = isFirstDigit; i <= min(9, s); i++)
    if (s - i <= (m - 1) * 9)
      return string(1, char(i + '0')) + solveMin(m - 1, s - i, 0);
  return "";
}

int main()
{
  ios::sync_with_stdio(0);
  int m, s;
  cin >> m >> s;
  
  if (!s)
  {
    cout << (m == 1 ? "0 0" : "-1 -1") << endl;
    return 0;
  }
  
  if (s > m * 9)
  {
    cout << "-1 -1\n";
    return 0;
  }
  
  cout << solveMin(m, s, 1) << ' ' << solveMax(m, s, 1) << endl;
}