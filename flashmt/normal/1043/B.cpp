#include <bits/stdc++.h>
using namespace std;

int n, a[1010];

int isGood(int k)
{
  int x[1010];
  for (int i = 0; i < k; i++)
    x[i] = a[i + 1] - a[i];
  for (int i = k + 1; i <= n; i++)
    if (a[i] - a[i - 1] != x[(i - 1) % k])
      return 0;
  return 1;
}

int main()
{
  ios::sync_with_stdio(0);
  
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  vector <int> ans;
  for (int k = 1; k <= n; k++)
    if (isGood(k))
      ans.push_back(k);
  cout << ans.size() << endl;
  for (int k : ans)
    cout << k << ' ';
}