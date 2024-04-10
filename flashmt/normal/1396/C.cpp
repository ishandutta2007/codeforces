#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  long long r1,  r2, r3, d;
  cin >> n >> r1 >> r2 >> r3 >> d;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<vector<long long>> f(n, vector<long long>(2, oo));
  f[0][0] = r1 * a[0] + r3;
  f[0][1] = min(r1 * (a[0] + 1), r2);

  for (int i = 1; i < n; i++)
  {
    long long cost1 = min(r1 * (a[i] + 1), r2);
    f[i][0] = min(f[i - 1][0], f[i - 1][1] + r1 + d * 2) + r1 * a[i] + r3 + d;
    f[i][0] = min(f[i][0], f[i - 1][1] + cost1 + r1 * 2 + d * 3);
    f[i][1] = f[i - 1][0] + cost1 + d;
  }

  long long ans = f[n - 1][0];
  ans = min(ans, f[n - 1][1] + r1 + d * 2);
  ans = min(ans, f[n - 2][1] + r1 * a[n - 1] + r3 + d * 2 + r1);
  cout << ans << endl;
}