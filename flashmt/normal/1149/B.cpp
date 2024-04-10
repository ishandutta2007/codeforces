#include <bits/stdc++.h>
using namespace std;
const int MAX = 250;

string s;
int n, nextId[26][100100], f[255][255][255], len[3], desc[3][255];

void remove(int z)
{
  if (z == 0)
  {
    for (int j = 0; j <= len[1]; j++)
      for (int k = 0; k <= len[2]; k++)
        f[len[0]][j][k] = n;
  }
  else if (z == 1)
  {
    for (int i = 0; i <= len[0]; i++)
      for (int k = 0; k <= len[2]; k++)
        f[i][len[1]][k] = n;
  }
  else
  {
    for (int i = 0; i <= len[0]; i++)
      for (int j = 0; j <= len[1]; j++)
        f[i][j][len[2]] = n;
  }
  len[z]--;
}

void updateF(int i, int j ,int k)
{
  if (i) 
    f[i][j][k] = min(f[i][j][k], nextId[desc[0][i]][f[i - 1][j][k] + 1]);
  if (j)
    f[i][j][k] = min(f[i][j][k], nextId[desc[1][j]][f[i][j - 1][k] + 1]);
  if (k)
    f[i][j][k] = min(f[i][j][k], nextId[desc[2][k]][f[i][j][k - 1] + 1]);
}

void add(int z, int ch)
{
  desc[z][++len[z]] = ch;
  if (z == 0)
  {
    for (int j = 0; j <= len[1]; j++)
      for (int k = 0; k <= len[2]; k++)
        updateF(len[0], j, k);
  }
  else if (z == 1)
  {
    for (int i = 0; i <= len[0]; i++)
      for (int k = 0; k <= len[2]; k++)
        updateF(i, len[1], k);
  }
  else
  {
    for (int i = 0; i <= len[0]; i++)
      for (int j = 0; j <= len[1]; j++)
        updateF(i, j, len[2]);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  int q, z;
  string kind, ch;
  cin >> n >> q >> s;
  
  vector <int> lastId(26, n);
  for (int c = 0; c < 26; c++)
    for (int i = n; i <= n + 5; i++)
      nextId[c][i] = n;

  for (int i = n - 1; i >= 0; i--)
  {
    lastId[s[i] - 'a'] = i;
    for (int c = 0; c < 26; c++)
      nextId[c][i] = lastId[c];
  }

  for (int i = 0; i <= MAX; i++)
    for (int j = 0; j <= MAX; j++)
      for (int k = 0; k <= MAX; k++)
        f[i][j][k] = n;
  f[0][0][0] = -1;

  while (q--)
  {
    cin >> kind >> z;
    if (kind == "+") 
    {
      cin >> ch;
      add(--z, ch[0] - 'a');
    }
    else remove(--z);

    cout << (f[len[0]][len[1]][len[2]] < n ? "YES" : "NO") << '\n';
  }
}