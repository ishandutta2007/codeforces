#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, b[7777];
  long long a[7777];
  map<long long, int> cnt;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    cnt[a[i]]++;
  }
  for (int i = 0; i < n; i++)
    cin >> b[i];

  vector<int> isGood(n, 0);
  for (int i = 0; i < n; i++)
    isGood[i] = cnt[a[i]] >= 2;

  long long ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if ((a[j] | a[i]) == a[j] && isGood[j])
      {
        ans += b[i];
        break;
      }

  cout << ans << endl;
}