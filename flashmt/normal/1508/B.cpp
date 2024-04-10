#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int m;
    long long k;
    cin >> m >> k;
    if (m == 1)
    {
      cout << (k == 1 ? 1 : -1) << '\n';
      continue;
    }
    int n = min(m, 61);
    if (1LL << n - 1 < k)
    {
      cout << -1 << '\n';
      continue;
    }

    k--;
    vector<int> bits(n - 1, 0);
    for (int i = 0; i < n - 1; i++)
      bits[i] = k >> i & 1;
    reverse(bits.begin(), bits.end());

    vector<int> a(n);
    for (int i = 0; i < n; i++)
      a[i] = i;
    for (int i = 0; i < n - 1;)
      if (bits[i])
      {
        int j = i;
        while (j < n - 1 && bits[j])
          j++;
        reverse(a.begin() + i, a.begin() + j + 1);
        i = j;
      }
      else i++;

    for (int i = 1; i <= m - n; i++)
      cout << i << ' ';
    for (int i = 0; i < n; i++)
      cout << m - n + 1 + a[i] << " \n"[i == n - 1];
  }
}