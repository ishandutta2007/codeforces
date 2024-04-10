#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[100100] = {0};
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    a[i] ^= a[i - 1];
  }

  if (n > 60)
  {
    cout << 1 << endl;
    return 0;
  }

  int ans = n + 1;
  for (int i = 0; i < n; i++)
    for (int j = i + 2; j <= n; j++)
      for (int k = i + 1; k < j; k++)
        if ((a[k] ^ a[i]) > (a[k] ^ a[j]))
          ans = min(ans, j - i - 2);

  cout << (ans <= n ? ans : -1) << endl;
}