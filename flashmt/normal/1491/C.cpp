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
    long long a[5050], s[5050] = {0};
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
      cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
      ans += max(0LL, a[i] - 1 - s[i]);
      for (int j = i + 2; j <= n && j <= i + a[i]; j++)
        s[j]++;

      if (s[i] >= a[i])
        s[i + 1] += s[i] - a[i] + 1;
    }

    cout << ans << endl;
  }
}