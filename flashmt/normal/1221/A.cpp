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
    int n, a[12] = {0}, x;
    cin >> n;
    while (n--)
    {
      cin >> x;
      for (int i = 0; i <= 11; i++)
        if ((1 << i) == x)
          a[i]++;
    }

    for (int i = 1; i <= 11; i++)
      a[i] += a[i - 1] / 2;

    cout << (a[11] ? "YES" : "NO") << endl;
  }
}