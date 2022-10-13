#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a[4];
  for (int i = 0; i < 4; i++)
    cin >> a[i];
  int sum = accumulate(a, a + 4, 0);
  
  for (int mask = 0; mask < 16; mask++)
  {
    int curSum = 0;
    for (int i = 0; i < 4; i++)
      curSum += a[i] * (mask >> i & 1);
    if (curSum * 2 == sum)
    {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}