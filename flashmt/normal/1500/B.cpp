#include <bits/stdc++.h>
using namespace std;
const int N = 5e5;

int n, m, a[N], b[N], idA[N * 2], idB[N * 2];
int flag[N]; // flag[i] * m = i mod n

long long countSame(long long t)
{
  int gcd = __gcd(m, n);
  long long lcm = 1LL * m / gcd * n, repeat = t / lcm, rem = t % lcm;
  long long res = 0;
  for (int i = 0; i < m; i++)
  {
    int j = idA[b[i]];
    if (j < 0)
      continue;
    if (i % gcd != j % gcd)
      continue;
    res += repeat;
    int num = flag[(j + n - i) % n];
    if (num >= 0 && 1LL * num * m + i < rem)
      res++;
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  if (n < m)
  {
    swap(m, n);
    swap(a, b);
  }

  memset(idA, -1, sizeof idA);
  memset(idB, -1, sizeof idB);
  memset(flag, -1, sizeof flag);
  for (int i = 0; i < n; i++)
    idA[--a[i]] = i;
  for (int i = 0; i < m; i++)
    idB[--b[i]] = i;

  for (int i = 0, id = 0; i <= n; i++)
  {
    if (flag[id] >= 0)
      break;
    flag[id] = i;
    id = (id + m) % n;
  }

  long long low = 1, high = 1LL << 60, ans = 0;
  while (low <= high)
  {
    long long mid = (low + high) / 2;
    if (mid - countSame(mid) < k) low = mid + 1;
    else
    {
      ans = mid;
      high = mid - 1;
    }
  }
  cout << ans << endl;
}