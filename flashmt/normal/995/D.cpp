#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(1 << n);
  for (int i = 0; i < 1 << n; i++)
    cin >> a[i];

  long long sum = accumulate(begin(a), end(a), 0LL);
  for (int i = 0; i <= q; i++)
  {
    cout << fixed << setprecision(9) << 1. * sum / (1 << n) << '\n';
    if (i < q)
    {
      int x, y;
      cin >> x >> y;
      sum += y - a[x];
      a[x] = y;
    }
  }
}