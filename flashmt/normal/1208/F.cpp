#include <bits/stdc++.h>
using namespace std;

int cnt[1 << 21];

void add(int x, int bit)
{
  if (cnt[x] >= 2)
    return;

  if (bit < 0)
  {
    cnt[x]++;
    return;
  }

  add(x, bit - 1);
  if (x >> bit & 1)
    add(x ^ 1 << bit, bit - 1);
}

int get(int x)
{
  int y = 0;
  for (int i = 20; i >= 0; i--)
    if (x >> i & 1 ^ 1)
      if (cnt[y | 1 << i] >= 2)
        y |= 1 << i;
  return x | y;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[1000100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    if (i + 3 <= n)
      ans = max(ans, get(a[i]));
    add(a[i], 20);
  }

  cout << ans << endl;
}