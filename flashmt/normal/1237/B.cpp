#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, id[100100];
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;
    id[x] = i;
  }

  int a[100100];
  for (int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;
    a[i] = id[x];
  }

  int ans = 0, minA = n + 1;
  for (int i = n; i; i--)
  {
    ans += a[i] > minA;
    minA = min(minA, a[i]);
  }
  cout << ans << endl;
}