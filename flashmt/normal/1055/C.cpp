#include <bits/stdc++.h>
using namespace std;

int main()
{
  int l, r, t, ll, rr, tt;
  cin >> l >> r >> t >> ll >> rr >> tt;
  if (t < tt)
  {
    swap(t, tt);
    swap(l, ll);
    swap(r, rr);
  }

  int g = __gcd(t, tt), diff = (l - ll + t) % t, ans = 0;
  for (int i = 0; i < 2; i++)
  {
    int shift = diff / g + i;
    ans = max(ans, min(r, rr + shift * g) - max(l, ll + shift * g) + 1);
    ans = max(ans, min(r + t, rr + shift * g) - max(l + t, ll + shift * g) + 1);
  }

  cout << ans << endl;
}