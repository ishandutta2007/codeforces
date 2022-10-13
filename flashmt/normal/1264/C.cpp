#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int n;
long long prob[200200], product[200200], sum[200200];

long long power(long long x, long long y)
{
  if (!y)
    return 1;
  long long res = power(x, y >> 1);
  res = res * res % BASE;
  if (y & 1)
    res = res * x % BASE;
  return res;
}

long long calc(int l, int r)
{
  long long sumLR = sum[r - 1];
  if (l > 1)
    sumLR = (sumLR - sum[l - 2] + BASE) % BASE;
  long long res = sumLR * power(product[r], BASE - 2);
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long inv100 = power(100, BASE - 2);
  int q;
  cin >> n >> q;

  product[0] = sum[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    cin >> prob[i];
    prob[i] = prob[i] * inv100 % BASE;
    product[i] = product[i - 1] * prob[i] % BASE;
    sum[i] = (sum[i - 1] + product[i]) % BASE;
  }

  set<int> checkpoints;
  checkpoints.insert(1);
  checkpoints.insert(n + 1);
  long long ans = calc(1, n);
  while (q--)
  {
    int x;
    cin >> x;
    if (checkpoints.count(x))
    {
      checkpoints.erase(x);
      auto r = checkpoints.lower_bound(x);
      assert(r != checkpoints.begin() && r != checkpoints.end());
      auto l = prev(r);
      ans = (ans - calc(*l, x - 1) - calc(x, *r - 1) + BASE * 2) % BASE;
      ans = (ans + calc(*l, *r - 1)) % BASE;
    }
    else
    {
      auto r = checkpoints.lower_bound(x);
      assert(r != checkpoints.begin() && r != checkpoints.end());
      auto l = prev(r);
      ans = (ans - calc(*l, *r - 1) + BASE) % BASE;
      checkpoints.insert(x);
      ans = (ans + calc(*l, x - 1) + calc(x, *r - 1)) % BASE;
    }
    cout << ans << '\n';
  }
}