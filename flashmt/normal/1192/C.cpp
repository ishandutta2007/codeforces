#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;
const int N = 62;

int toInt(char c)
{
  if (c >= 'a' && c <= 'z')
    return c - 'a';
  if (c >= 'A' && c <= 'Z')
    return c - 'A' + 26;
  return c - '0' + 52;
}

long long solve(set<string> a)
{
  int cnt[N][N] = {0};
  int f[N][N][N] = {0};
  for (auto s : a)
  {
    int x = toInt(s[0]), y = toInt(s.back());
    cnt[x][y]++;
  }

  for (int i = 0; i < N; i++)
    for (int j = i; j < N; j++)
      for (int p = j; p < N; p++)
        for (int q = 0; q < N; q++)
        {
          long long ways = 1LL * cnt[i][q] * cnt[j][q] % BASE * cnt[p][q] % BASE;
          f[i][j][p] += ways;
          if (f[i][j][p] >= BASE)
            f[i][j][p] -= BASE;
        }

  long long res = 0;
  for (int i = 0; i < N; i++)
    for (int j = i; j < N; j++)
      for (int p = j; p < N; p++)
        for (int q = p; q < N; q++)
        {
          long long ways = 1LL * f[i][j][p] * f[i][j][q] % BASE;
          ways = ways * f[i][p][q] % BASE;
          ways = ways * f[j][p][q] % BASE;
          if (i == q) res += ways;
          else if (i == p || j == q) res += ways * 4;
          else if (i == j && p == q) res += ways * 6;
          else if (i == j || j == p || p == q) res += ways * 12;
          else res += ways * 24;
          res %= BASE;
        }

  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  string s;
  set<string> a[11];
  cin >> n;
  while (n--)
  {
    cin >> s;
    a[s.size()].insert(s);
    reverse(s.begin(), s.end());
    a[s.size()].insert(s);
  }

  long long ans = 0;
  for (int i = 3; i <= 10; i++)
    ans = (ans + solve(a[i])) % BASE;
  cout << ans << endl;
}