#include <bits/stdc++.h>
using namespace std;

int n, f[19][1 << 18], toId[19][1 << 18], r[1 << 18], id[1 << 18];
string s;

void update(int round, int match)
{
  f[round][match] = 0;
  int curId = toId[round][match];
  if (s[curId] != '0')
    f[round][match] += f[round - 1][match * 2 + 1];
  if (s[curId] != '1')
    f[round][match] += f[round - 1][match * 2];
  if (round < n)
    update(round + 1, match / 2);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s;

  for (int i = 0; i < 1 << n; i++)
    f[0][i] = 1;

  int curId = 0;
  for (int round = 1; round <= n; round++)
    for (int i = 0; i < 1 << (n - round); i++)
    {
      id[curId] = i;
      r[curId] = round;
      toId[round][i] = curId;
      if (s[curId] != '0')
        f[round][i] += f[round - 1][i * 2 + 1];
      if (s[curId] != '1')
        f[round][i] += f[round - 1][i * 2];
      curId++;
    }

  int q;
  cin >> q;
  while (q--)
  {
    int i;
    char c;
    cin >> i >> c;
    s[--i] = c;
    update(r[i], id[i]);
    cout << f[n][0] << '\n';
  }
}