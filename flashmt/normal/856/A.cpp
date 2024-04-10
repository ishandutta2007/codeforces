#include <bits/stdc++.h>
using namespace std;
const int MAX = int(1e6);

int flag[MAX * 2 + 10];

int main()
{
  int test, n, a[111];
  cin >> test;
  for (int iTest = 1; iTest <= test; iTest++)
  {
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a, a + n);

    vector <int> b;
    for (int x = 1; x <= MAX; x++)
    {
      int good = 1;
      for (int i = 0; i < n; i++)
        if (flag[a[i] + x] == iTest)
        {
          good = 0;
          break;
        }

      if (good)
      {
        b.push_back(x);
        for (int i = 0; i < n; i++)
          flag[a[i] + x] = iTest;
        if (b.size() == n)
          break;
      }
    }

    if (b.size() < n) cout << "NO" << endl;
    else
    {
      cout << "YES" << endl;
      for (int x : b)
        cout << x << ' ';
      cout << endl;
    }
  }
}