#include <bits/stdc++.h>
using namespace std;
const int BASE = 998244353;

int n, m, a[55], w[55];
long long inv[5555];

long long power(long long x, int y)
{
  if (!y) 
    return 1;
  long long r = power(x, y / 2);
  r = r * r % BASE;
  if (y % 2)
    r = r * x % BASE;
  return r;
}

void solve(int id)
{
  int sumLike = 0, sumDislike = 0;
  for (int i = 0; i < n; i++)
    if (i != id)
    {
      if (a[i] > 0) sumLike += w[i];
      else sumDislike += w[i];
    }

  long long f[55][55][55] = {0};
  f[0][0][0] = 1;

  for (int turn = 0; turn < m; turn++)
    for (int like = 0; like <= turn; like++)
      for (int hit = 0; hit <= turn; hit++)
      {
        int curW = w[id] + hit * a[id];
        int curSumLike = sumLike + like;
        int curSumDislike = sumDislike - (turn - hit - like);
        long long each = f[turn][like][hit] * inv[curW + curSumLike + curSumDislike] % BASE;

        if (curW)
          f[turn + 1][like][hit + 1] = (f[turn + 1][like][hit + 1] + curW * each) % BASE;
        if (curSumLike)
          f[turn + 1][like + 1][hit] = (f[turn + 1][like + 1][hit] + curSumLike * each) % BASE;
        if (curSumDislike)
          f[turn + 1][like][hit] = (f[turn + 1][like][hit] + curSumDislike * each) % BASE;
      }

  long long res = 0;
  for (int like = 0; like <= m; like++)
    for (int hit = 0; hit <= m; hit++)
      res = (res + f[m][like][hit] * (w[id] + hit * a[id])) % BASE;

  cout << res << endl;
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (!a[i])
      a[i] = -1;
  }
  for (int i = 0; i < n; i++)
    cin >> w[i];

  for (int i = 1; i <= 5000; i++)
    inv[i] = power(i, BASE - 2);

  for (int i = 0; i < n; i++)
    solve(i);
}