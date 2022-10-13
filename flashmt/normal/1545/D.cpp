#include <bits/stdc++.h>
using namespace std;

int n, k, a[1010][1010];
long long s[1010], sSqr[1010];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < k; i++)
    for (int j = 0; j < n; j++)
    {
      cin >> a[i][j];
      s[i] += a[i][j];
      sSqr[i] += 1LL * a[i][j] * a[i][j];
    }

  long long sumV, sumVSqr;
  for (int i = 1; i < k - 1; i++)
    if (s[i] - s[i - 1] == s[i + 1] - s[i])
    {
      sumV = s[i] - s[i - 1];
      sumVSqr = (sSqr[i - 1] + sSqr[i + 1]) / 2 - sSqr[i];
      break;
    }

  int bad = -1;
  for (int i = 1; i < k - 1; i++)
    if (s[i] != s[0] + sumV * i)
    {
      bad = i;
      break;
    }

  long long expectedSSqr = (sSqr[bad - 1] + sSqr[bad + 1]) / 2 - sumVSqr;
  long long diffS = sumV - (s[bad] - s[bad - 1]);
  for (int j = 0; j < n; j++)
  {
    long long newA = a[bad][j] + diffS;
    long long newSSqr = sSqr[bad] - 1LL * a[bad][j] * a[bad][j] + newA * newA;
    if (newSSqr == expectedSSqr)
    {
      cout << bad << ' ' << newA << endl;
      cout.flush();
      return 0;
    }
  }

  assert(0);
}