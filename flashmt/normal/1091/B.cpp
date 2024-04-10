#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  long long sumX = 0, sumY = 0;
  cin >> n;
  for (int i = 0; i < n * 2; i++)
  {
    int x, y;
    cin >> x >> y;
    sumX += x;
    sumY += y;
  }
  cout << sumX / n << ' ' << sumY / n << endl;
}