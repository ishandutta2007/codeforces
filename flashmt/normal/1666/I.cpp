#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int ask(int x, int y)
{
  cout << "SCAN " << x << ' ' << y << endl;
  cout.flush();
  int resp;
  cin >> resp;
  return resp;
}

int query(int x, int y)
{
  cout << "DIG " << x << ' ' << y << endl;
  cout.flush();
  int resp;
  cin >> resp;
  return resp;
}

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int n, m;
    cin >> n >> m;
    int sumXY = ask(1, 1) + 4;
    int diffXY = ask(1, m) - m * 2 + 2;
    int sumX = (sumXY + diffXY) / 2;
    int sumY = sumXY - sumX;
    int diffX = ask(sumX / 2, 1) + 2 - sumY;
    int diffY = ask(1, sumY / 2) + 2 - sumX;
    int xx = (sumX + diffX) / 2, x = sumX - xx;
    int yy = (sumY + diffY) / 2, y = sumY - yy;
    if (query(x, y)) query(xx, yy);
    else
    {
      query(x, yy);
      query(xx, y);
    }
  }
}