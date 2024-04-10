#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test, n, a[100100];
  cin >> test;
  while (test--)
  {
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a, a + n);
    cout << min(n - 2, a[n - 2] - 1) << '\n';
  }
}