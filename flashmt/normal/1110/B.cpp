#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k, a[100100];
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> b;
  for (int i = 1; i < n; i++)
    b.push_back(a[i] - a[i - 1] - 1);
  sort(b.begin(), b.end());

  long long ans = n;
  for (int i = 0; i < n - k; i++)
    ans += b[i];
  cout << ans << endl;
}