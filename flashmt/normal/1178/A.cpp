#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[100];
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int mySum = a[0], otherSum = 0;
  vector<int> ans(1, 0);
  for (int i = 1; i < n; i++)
    if (a[i] * 2 <= a[0])
    {
      mySum += a[i];
      ans.push_back(i);
    }
    else otherSum += a[i];

  if (mySum <= otherSum) cout << 0 << endl;
  else
  {
    cout << ans.size() << endl;
    for (int x : ans)
      cout << x + 1 << ' ';
  }
}