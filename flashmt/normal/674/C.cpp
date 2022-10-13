// see how fast G++20 can be

#include <bits/stdc++.h>
using namespace std;
const int N = 200200;
const int K = 55;
const double oo = 1e18;

int n, k;
long long a[N];
double f[K][N], b[N], suffixCost[N];

void calc(int i, int low, int high, int optL, int optR)
{
  if (low > high)
    return;

  int mid = (low + high) / 2, optM = -1;
  f[i][mid] = oo;
  for (int j = optL; j <= min(optR, mid - 1); j++)
  {
    double curF = f[i - 1][j] + suffixCost[j + 1] - suffixCost[mid + 1] - (a[mid] - a[j]) * (b[n] - b[mid]);
    if (curF < f[i][mid])
    {
      f[i][mid] = curF;
      optM = j;
    }
  }

  calc(i, low, mid - 1, optL, optM);
  calc(i, mid + 1, high, optM, optR);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    b[i] = b[i - 1] + 1. / a[i];
    a[i] += a[i - 1];
  }

  suffixCost[n] = 1;
  for (int i = n - 1; i; i--)
    suffixCost[i] = suffixCost[i + 1] + (a[i] - a[i - 1]) * (b[n] - b[i - 1]);

  for (int i = 1; i <= n; i++)
    f[0][i] = oo;
  for (int i = 1; i <= k; i++)
    calc(i, i, n, i - 1, n);

  cout << fixed << setprecision(9) << f[k][n] << endl;
}