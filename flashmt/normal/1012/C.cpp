#include <bits/stdc++.h>
using namespace std;
const int oo = 1 << 30;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 2);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  vector<int> f(n + 1, oo);
  for (int i = 1; i <= (n + 1) / 2; i++)
  {
    vector<int> newF(n + 1, oo), prefix(n + 1, oo);
    for (int j = 1; j <= n; j++)
      prefix[j] = min(prefix[j - 1], f[j]);

    int ans = oo;
    for (int j = i * 2 - 1; j <= n; j++)
    {
      int costL = max(0, a[j - 1] - a[j] + 1);
      int costL2 = max(0, min(a[j - 2] - 1, a[j - 1]) - a[j] + 1);
      int costR = max(0, a[j + 1] - a[j] + 1);
      if (i == 1) newF[j] = costL + costR;
      else newF[j] = min(prefix[j - 3] + costL + costR, f[j - 2] + costL2 + costR);
      ans = min(ans, newF[j]);
    }
    swap(f, newF);
    cout << ans << ' ';
  }
}