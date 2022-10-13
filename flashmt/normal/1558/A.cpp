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
    int a, b;
    cin >> a >> b;
    int n = a + b;
    vector<int> good(n + 1);
    for (int i = 0; i <= (n + 1) / 2; i++)
      if (i <= a)
      {
        int j = n / 2 - (a - i);
        if (j >= 0 && j <= b)
          good[i + j] = 1;
      }
    for (int i = 0; i <= n / 2; i++)
      if (i <= a)
      {
        int j = (n + 1) / 2 - (a - i);
        if (j >= 0 && j <= b)
          good[i + j] = 1;
      }

    cout << accumulate(begin(good), end(good), 0) << '\n';
    for (int i = 0; i <= n; i++)
      if (good[i])
        cout << i << ' ';
    cout << '\n';
  }
}