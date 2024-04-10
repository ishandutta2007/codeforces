#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k, a[200200];
  long long s[200200] = {0};
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++)
    s[i] = s[i - 1] + a[i];

  long long ans = 1LL << 60;
  for (int i = 1, j = 1; i <= n;)
  {
    while (j <= n && a[j] == a[i])
      j++;
    if (j - i >= k)
    {
      ans = 0;
      break;
    }

    int need = k - (j - i);
    // calculate cost to make left/right part equal to a[i] - 1 or a[i] + 1
    long long costLeft = (a[i] - 1LL) * (i - 1) - s[i - 1];
    long long costRight = s[n] - s[j - 1] - (a[i] + 1LL) * (n - j + 1);
    if (i - 1 >= need)
      ans = min(ans, costLeft + need);
    if (n - j + 1 >= need)
      ans = min(ans, costRight + need);
    ans = min(ans, costLeft + costRight + need);

    i = j;
  }

  cout << ans << endl;
}