#include <bits/stdc++.h>
using namespace std;
const string DIRECTION = "NEWS";

string s[2];
int n, a[2][1000100], pre[1000100];

void calcPre(int p[])
{
  int i = 0, j = -1;
  pre[0] = -1;
  while (i < n)
  {
    while (j >= 0 && p[i] != p[j]) j = pre[j];
    i++; j++;
    pre[i] = (j >= n || p[i] != p[j] ? j : pre[j]);
  }
}

int suffixMatch(int s[], int p[])
{
  int i = 0, j = 0;
  while (i < n)
  {
    while (j >=0 && s[i] != p[j]) j = pre[j];
    i++; 
    j++;
  }
  return j;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s[0] >> s[1];
  n--;
  for (int z = 0; z < 2; z++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < 4; j++)
        if (s[z][i] == DIRECTION[j])
          a[z][i] = j;

  reverse(a[0], a[0] + n);
  for (int i = 0; i < n; i++)
    a[0][i] = 3 - a[0][i];

  calcPre(a[0]);
  cout << (suffixMatch(a[1], a[0]) ? "NO": "YES") << endl;
}