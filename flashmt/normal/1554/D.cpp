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
    if (n <= 26)
    {
      for (int i = 0; i < n; i++)
        cout << char(i + 'a');
      cout << '\n';
    }
    else
    {
      int half = n / 2;
      cout << string(half, 'a');
      for (int i = 0; i < n - half * 2 + 1; i++)
        cout << char('b' + i);
      cout << string(half - 1, 'a') << '\n';
    }
  }
}