#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  for (int i = 1; i <= 30; i++)
    if ((1 << i) - 1 >= n)
    {
      cout << i << endl;
      return 0;
    }
}