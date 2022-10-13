#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  string x, y;
  cin >> test;
  while (test--)
  {
    cin >> x >> y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    for (int i = 0; i < y.size(); i++)
      if (y[i] == '1')
      {
        for (int j = i; j < x.size(); j++)
          if (x[j] == '1')
          {
            cout << j - i << '\n';
            break;
          }
        break;
      }
  }
}