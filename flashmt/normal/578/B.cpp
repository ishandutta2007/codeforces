#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, k, x;
  unsigned long long a[200200], l[200200] = {0};

  cin >> n >> k >> x;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    l[i] = l[i - 1] | a[i];
  }

  unsigned long long r = 0, ans = 0;
  for (int i = n; i; i--)
  {
    long long cur = a[i];
    for (int j = 0; j < k; j++)
      cur *= x;
    ans = max(ans, l[i - 1] | r | cur);
    r |= a[i];
  }

  cout << ans << endl;
}