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
  sort(a, a + n);

  vector<int> flag(n, 0);
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (!flag[i])
    {
      ans++;
      for (int j = i; j < n; j++)
        if (a[j] % a[i] == 0)
          flag[j] = 1;
    }

  cout << ans << endl;
}