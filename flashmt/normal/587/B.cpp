#include <bits/stdc++.h>
using namespace std;
const int BASE = int(1e9) + 7;

int n, k;
pair <int,int> a[1000100];
long long l, f[2][1000100];

long long get(int id, int length)
{
  long long occurrence = l / n + (id < l % n);
  return max(0LL, (occurrence - length + 1) % BASE);
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n >> l >> k;

  for (int i = 0; i < n; i++)
  {
    cin >> a[i].first;
    a[i].second = i;
  }

  sort(a, a + n);

  long long ans = 0;
  int z = 0;
  for (int j = 0; j < n; j++)
  {
    f[0][j] = j + 1;
    ans = (ans + get(a[j].second, 1)) % BASE;
  }

  for (int i = 2; i <= k; i++)
  {
    z ^= 1;
    for (int j = 0; j < n; j++)
      f[z][j] = 0;
    
    for (int j = 0; j < n;)
    {
      int k = j;
      while (k + 1 < n && a[k + 1].first == a[j].first)
        k++;
      while (j <= k)
      {
        f[z][j] = f[z ^ 1][k];
        if (j) f[z][j] = (f[z][j] + f[z][j - 1]) % BASE;
        ans = (ans + f[z ^ 1][k] * get(a[j].second, i)) % BASE;
        j++;
      }
    }
  }

  cout << ans << endl;
}