#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q, cnt[2] = {0}, a[100100];
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    cnt[a[i]]++;
  }

  while (q--)
  {
    int t, x;
    cin >> t >> x;
    if (t == 1)
    {
      cnt[a[x]]--;
      a[x] ^= 1;
      cnt[a[x]]++;
    }
    else
    {
      cout << (cnt[1] >= x) << '\n';
    }
  }
}