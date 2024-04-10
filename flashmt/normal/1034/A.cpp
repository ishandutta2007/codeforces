#include <bits/stdc++.h>
using namespace std;
const int MAX = 15000000;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, a[300300], g = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    g = gcd(g, a[i]);
  }

  vector<int> divisor(MAX + 5, 0);
  for (int i = 2; i * i <= MAX; i++)
    if (!divisor[i])
      for (int j = i * i; j <= MAX; j += i)
        divisor[j] = i;

  vector<int> cnt(MAX + 5, 0);
  for (int i = 0; i < n; i++)
  {
    int x = a[i] / g;
    set<int> s;
    while (divisor[x])
    {
      s.insert(divisor[x]);
      x /= divisor[x];
    }
    s.insert(x);
    for (int d : s)
      cnt[d]++;
  }

  int ans = n + 1;
  for (int i = 2; i <= MAX; i++)
    if (!divisor[i] && cnt[i])
      ans = min(ans, n - cnt[i]);

  cout << (ans > n ? -1 : ans) << endl;
}