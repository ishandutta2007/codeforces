#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      sum += x;
    }
    sum -= n;
    cout << (sum % 2 ? "errorgorn" : "maomao90") << endl;
  }
}