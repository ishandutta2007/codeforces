#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e9 + 7;

int n, l[200200], r[200200];
long long equalProb[200200];

long long power(int x, int y)
{
  if (!y)
    return 1;
  long long res = power(x, y / 2);
  res = res * res % BASE;
  if (y % 2)
    res = res * x % BASE;
  return res;
}

long long calcPair(int i)
{
  long long allCases = 1LL;
  int maxL = -1, minR = 1 << 30;
  for (int j = i - 1; j <= i + 1; j++)
  {
    allCases = allCases * (r[j] - l[j]) % BASE;
    maxL = max(maxL, l[j]);
    minR = min(minR, r[j]);
  }
  long long equalTriple = max(0, minR - maxL) * power(allCases, BASE - 2) % BASE;
  return (1 - equalProb[i] - equalProb[i + 1] + equalTriple + BASE * 2) % BASE;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> l[i];
  for (int i = 1; i <= n; i++)
  {
    cin >> r[i];
    r[i]++;
  }
  r[0] = 1;

  long long sumP[200200] = {0};
  for (int i = 1; i <= n; i++)
  {
    long long allCases = 1LL * (r[i - 1] - l[i - 1]) * (r[i] - l[i]) % BASE;
    equalProb[i] = max(0, min(r[i], r[i - 1]) - max(l[i], l[i - 1])) * power(allCases, BASE - 2) % BASE;
    sumP[i] = (sumP[i - 1] + 1 - equalProb[i] + BASE) % BASE;
  }

  long long ans = sumP[n];
  for (int i = 1; i <= n; i++)
  {
    long long prob = (sumP[i] - sumP[i - 1] + BASE) % BASE;
    if (i - 2 > 0)
      ans = (ans + prob * sumP[i - 2]) % BASE;
    if (i + 2 <= n)
      ans = (ans + prob * (sumP[n] - sumP[i + 1] + BASE)) % BASE;
    if (i > 1)
      ans = (ans + calcPair(i - 1)) % BASE;
    if (i < n)
      ans = (ans + calcPair(i)) % BASE;
  }

  cout << ans << endl;
}