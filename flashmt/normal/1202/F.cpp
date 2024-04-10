#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b;
  cin >> a >> b;

  int ans = 0;
  for (int i = 1; i * i <= a + b; i++)
  {
    int low = (a + b) / (i + 1) + 1, high = (a + b) / i;
    int minA = (a + i) / (i + 1), maxA = a / i;
    int minB = (b + i) / (i + 1), maxB = b / i;
    if (minA <= maxA && minB <= maxB)
      ans += min(maxA + maxB, high) - max(minA + minB, low) + 1;

    int j = (a + b) / i;
    if (j == i)
      continue;
    minA = (a + j) / (j + 1), maxA = a / j;
    minB = (b + j) / (j + 1), maxB = b / j;
    ans += minA + minB <= i && i <= maxA + maxB && minA <= maxA && minB <= maxB;
  }
  cout << ans << endl;
}