#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    set<int> s;
    for (int i = 0; i < 2; i++)
      for (int x = 2; x * x <= n; x++)
        if (n % x == 0 && !s.count(x))
        {
          n /= x;
          s.insert(x);
          break;
        }

    if (n > 1)
      s.insert(n);

    if (s.size() == 3)
    {
      cout << "YES\n";
      for (int x : s)
        cout << x << ' ';
      cout << '\n';
    }
    else cout << "NO\n";
  }
}