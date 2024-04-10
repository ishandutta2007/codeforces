#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int m, n;
    cin >> m >> n;
    set<int> s;
    for (int i = 0; i < m + n; i++)
    {
      int x;
      cin >> x;
      s.insert(x);
    }
    cout << m + n - s.size() << endl;
  }
}