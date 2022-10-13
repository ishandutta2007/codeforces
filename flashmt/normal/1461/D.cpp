#include <bits/stdc++.h>
using namespace std;

int a[100100];
long long sum[100100];
unordered_set<long long> s;

void go(int l, int r)
{
  s.insert(sum[r] - sum[l - 1]);
  if (a[l] == a[r])
    return;

  int m = upper_bound(a + l, a + r + 1, (a[l] + a[r]) / 2) - a;
  if (m == l || m > r)
    return;
  go(l, m - 1);
  go(m, r);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
      sum[i] = sum[i - 1] + a[i];

    s.clear();
    go(1, n);

    while (q--)
    {
      int x;
      cin >> x;
      cout << (s.count(x) ? "Yes" : "No") << '\n';
    }
  }
}