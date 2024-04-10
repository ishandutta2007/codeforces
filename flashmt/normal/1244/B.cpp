#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    string a;
    cin >> n >> a;
    int ans = n;
    for (int i = 0; i < n; i++)
      if (a[i] == '1')
        ans = max(ans, (n - min(i, n - 1 - i)) * 2);
    cout << ans << endl;
  }
}