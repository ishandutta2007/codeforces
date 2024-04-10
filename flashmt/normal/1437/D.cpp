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
    int n, a[200200], ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int i = 1, cnt = 1;
    while (1)
    {
      int j = i;
      ans++;
      while (cnt-- && j < n)
      {
        j++;
        while (j < n && a[j] > a[j - 1])
          j++;
      }
      if (j >= n)
        break;
      cnt = j - i;
      i = j;
    }

    cout << ans << endl;
  }
}