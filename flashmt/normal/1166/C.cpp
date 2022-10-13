#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, a[200200];
  cin >> n;
  for (int i = 0 ; i < n; i++)
  {
    cin >> a[i];
    a[i] = abs(a[i]);
  }

  sort(a, a + n);
  long long ans = n * (n - 1LL) / 2;
  for (int i = 0, j = 0; i < n; i++)
  {
    while (a[j] * 2 < a[i])
      j++;
    ans -= j;
  }
  cout << ans << endl;
}