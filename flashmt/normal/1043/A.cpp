#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, x, sum = 0, maxX = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    maxX = max(x, maxX);
    sum += x;
  }
  cout << max(maxX, sum * 2 / n + 1) << endl;
}