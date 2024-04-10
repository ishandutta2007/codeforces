#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;
const long long oo = 1LL << 60;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, budget;
  cin >> n >> budget;
  vector<long long> maxDH(budget + 2);
  while (n--)
  {
    int c, d, h;
    cin >> c >> d >> h;
    maxDH[c] = max(maxDH[c], 1LL * d * h);
  }

  for (int i = 1; i <= budget; i++)
    for (int j = 2; i * j <= budget; j++)
      maxDH[i * j] = max(maxDH[i * j], maxDH[i] * j);

  for (int i = 1; i <= budget; i++)
    maxDH[i] = max(maxDH[i], maxDH[i - 1]);
  maxDH[budget + 1] = oo;

  int m;
  cin >> m;
  while (m--)
  {
    long long d, h;
    cin >> d >> h;
    int ans = upper_bound(begin(maxDH), end(maxDH), d * h) - begin(maxDH);
    cout << (ans <= budget ? ans : -1) << ' ';
  }
}