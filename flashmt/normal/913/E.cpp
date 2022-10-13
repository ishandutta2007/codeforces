#include <bits/stdc++.h>
using namespace std;

string f[1 << 8][3], ans[1 << 8];

int update(string &s, string t)
{
  if (empty(s) || size(s) > size(t) || (size(s) == size(t) && s > t))
  {
    s = t;
    return 1;
  }
  return 0;
}

void init()
{
  f[1 << 4 | 1 << 5 | 1 << 6 | 1 << 7][0] = "x";
  f[1 << 2 | 1 << 3 | 1 << 6 | 1 << 7][0] = "y";
  f[1 << 1 | 1 << 3 | 1 << 5 | 1 << 7][0] = "z";
  while (1)
  {
    int found = 0;
    for (int i = 0; i < 1 << 8; i++)
      for (int j = 0; j < 3; j++)
      {
        if (empty(f[i][j]))
          continue;

        // not
        {
          string s = j ? "(" + f[i][j] + ")" : f[i][j];
          found |= update(f[i ^ ((1 << 8) - 1)][0], "!" + s);
        }

        for (int ii = 0; ii < 1 << 8; ii++)
          for (int jj = 0; jj < 3; jj++)
          {
            if (empty(f[ii][jj]))
              continue;

            // and
            {
              string s = j == 2 ? "(" + f[i][j] + ")" : f[i][j];
              string ss = jj == 2 ? "(" + f[ii][jj] + ")" : f[ii][jj];
              found |= update(f[i & ii][1], s + "&" + ss);
            }

            // or
            found |= update(f[i | ii][2], f[i][j] + "|" + f[ii][jj]);
          }
      }

    if (!found)
      break;
  }

  for (int i = 0; i < 1 << 8; i++)
    for (int j = 0; j < 3; j++)
      if (!empty(f[i][j]))
        update(ans[i], f[i][j]);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  init();
  int test;
  cin >> test;
  while (test--)
  {
    string s;
    cin >> s;
    int mask = 0;
    for (int i = 0; i < 8; i++)
      mask |= (s[i] - '0') << i;
    cout << ans[mask] << '\n';
  }
}