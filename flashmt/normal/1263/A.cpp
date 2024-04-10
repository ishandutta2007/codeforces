#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int x, y, z;
    cin >> x >> y >> z;
    int maxValue = max({x, y, z});
    cout << (maxValue * 2 <= x + y + z ? (x + y + z) / 2 : x + y + z - maxValue) << endl;
  }
}