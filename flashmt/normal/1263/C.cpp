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
    set<int> s;
    for (int i = 1; i * i <= n; i++)
    {
      s.insert(i);
      s.insert(n / i);
    }

    cout << s.size() + 1 << endl << 0;
    for (int x : s)
      cout << ' ' << x;
    cout << endl;
  }
}