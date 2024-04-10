#include <bits/stdc++.h>
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
    while (n--)
    {
      int x;
      cin >> x;
      for (int i = 29; i >= 0; i--)
        if (1 << i <= x)
        {
          cout << (1 << i) << ' ';
          break;
        }
    }
    cout << endl;
  }
}