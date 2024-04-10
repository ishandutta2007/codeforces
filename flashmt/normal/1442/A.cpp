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
    int n, a[30300];
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    a[0] = a[1];

    long long sumSuffix[30300] = {0};
    for (int i = n - 1; i; i--)
      sumSuffix[i] = sumSuffix[i + 1] + max(0, a[i] - a[i + 1]);

    string ans = "NO";
    if (!sumSuffix[1]) ans = "YES";
    else
      for (int i = 1; i <= n; i++)
        if (a[i] > a[i - 1])
        {
          if (a[i - 1] >= sumSuffix[i])
            ans = "YES";
          break;
        }
        else if (i == n) ans = "YES";

    cout << ans << endl;
  }
}