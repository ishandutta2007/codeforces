#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int tree[2][200200], numId;

void add(int parity, int x)
{
  for (int i = x; i <= numId; i += i & -i)
    tree[parity][i]++;
}

int get(int parity, int x)
{
  int res = 0;
  for (int i = x; i; i -= i & -i)
    res += tree[parity][i];
  return res;
}

int solve(int a[], int n, long long bound)
{
  vector<long long> s(n + 1), s2(n + 1);
  map<long long, int> id;
  for (int i = 1; i <= n; i++)
  {
    s[i] = s[i - 1] + a[i];
    s2[i] = a[i];
    if (i >= 2)
      s2[i] += s2[i - 2];
    id[s[i] - s2[i]] = 0;
  }

  numId = 0;
  for (auto [k, _] : id)
    id[k] = ++numId;
  for (int i = 0; i <= numId; i++)
    tree[0][i] = tree[1][i] = 0;

  long long res = 0;
  for (int i = 1; i < n; i++)
  {
    add(i % 2, id[s[i] - s2[i]]);
    auto it = id.upper_bound(bound - s2[i]);
    if (it != id.begin())
      res += get(i % 2, (--it)->second);
  }

  return res % BASE;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test, n, a[200200], b[200200];
  cin >> test;
  while (test--)
  {
    cin >> n;
    vector<long long> s(n + 1);
    for (int i = 1; i <= n; i++)
    {
      cin >> a[i];
      s[i] = s[i - 1] + a[i];
    }

    long long bound = (s[n] - 1) / 2;
    int ans = 0;

    // (B)(A)
    for (int i = 1; i <= n; i++)
      if (s[n] - s[i] <= bound)
        ans++;

    for (int l = 0; l < 2; l++) // start with B
      for (int r = 0; r < 2; r++) // end with A
      {
        // [B](A)-(BA)-(B)[A]
        int m = 0;
        for (int i = l + 1; i <= n - r; i++)
          b[++m] = a[i];
        ans += solve(b, m, bound - r * a[n]);
        ans %= BASE;
      }

    cout << ans << '\n';
  }
}