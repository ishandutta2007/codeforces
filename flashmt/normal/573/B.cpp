#include <bits/stdc++.h>
using namespace std;
const int oo = 1000111000;

int n, h[100100], f[100100];

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> h[i];  

  int best = 1, ans = 1;
  f[0] = 1;
  for (int i = 0; i < n; i++)
  {
    best = min(best, h[i] - i);
    f[i] = i + best;
  }

  best = n;
  for (int i = n - 1; i >= 0; i--)
  {
    best = min(best, h[i] + i);
    f[i] = min(f[i], best - i);
    ans = max(ans, f[i]);
  }

  cout << ans << endl;
}