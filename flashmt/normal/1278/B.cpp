#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int a, b;
    cin >> a >> b;
    a = abs(a - b);
    for (int i = 0, sum = 0; ; i++)
    {
      sum += i;
      if (sum % 2 == a % 2 && sum >= a)
      {
        cout << i << endl;
        break;
      }
    }
  }
}