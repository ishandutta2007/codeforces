#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, l[100100], r[100100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> l[i] >> r[i];

  sort(l, l + n);
  sort(r, r + n);

  long long ans = 0;
  for (int i = 0; i < n; i++)
    ans += max(l[i], r[i]);

  cout << ans + n << endl;
}