#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 50;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  while (test--)
  {
    int n, tag[5555], s[5555];
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> tag[i];
    for (int i = 1; i <= n; i++)
      cin >> s[i];

    vector<long long> f(n + 1, 0), g(n + 1, -oo);
    for (int i = 1; i <= n; i++)
    {
      f[i] = 0;
      for (int j = i - 1; j; j--)
        if (tag[j] != tag[i])
        {
          g[j] = max(g[j], f[i] + abs(s[i] - s[j]));
          f[i] = max(f[i], f[j] + abs(s[i] - s[j]));
        }
      for (int j = 1; j < i; j++)
        f[j] = max(f[j], g[j]);
    }

    cout << *max_element(f.begin(), f.end()) << endl;
  }
}