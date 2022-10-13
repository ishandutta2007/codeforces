#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long n, m, k, p[100100];
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++)
  {
    cin >> p[i];
    p[i]--;
  }

  int ans = 0;
  for (int i = 0; i < m;)
  {
    int j = i + 1;
    while (j < m && (p[j] - i) / k == (p[i] - i) / k)
      j++;
    ans++;
    i = j;
  }

  cout << ans << endl;
}