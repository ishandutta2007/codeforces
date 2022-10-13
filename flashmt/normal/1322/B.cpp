#include <bits/stdc++.h>
using namespace std;

int n, b[400400];

long long countPair(int maxVal)
{
  long long res = 0;
  for (int i = 0, j = n - 1; i < n; i++)
  {
    while (j && b[j] + b[i] > maxVal)
      j--;
    if (b[i] + b[j] <= maxVal)
      res += max(0, j - i);
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = 0;
  for (int bit = 0; bit < 25; bit++)
  {
    for (int i = 0; i < n; i++)
      b[i] = a[i] & ((1 << bit + 1) - 1);
    sort(b, b + n);

    long long cnt = 0;
    if (!bit) cnt = countPair(1) - countPair(0);
    else
    {
      cnt = (n - 1LL) * n / 2;
      cnt -= countPair((1 << bit) - 1);
      cnt -= countPair((1 << bit + 1) + (1 << bit) - 1) - countPair((1 << bit + 1) - 1);
    }

    ans |= cnt % 2 << bit;
  }

  cout << ans << endl;
}