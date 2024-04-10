#include <bits/stdc++.h>
using namespace std;
const int BASE[] = {979983737, 989991077};
const int P[] = {67, 401};

string s, t;
int n;
long long h[2][1000100], pw[2][1000100];

void initHash(long long h[], long long pw[], int p, int base)
{
  pw[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    pw[i] = pw[i - 1] * p % base;
    h[i] = (h[i - 1] + pw[i] * (t[i] - 'a' + 1)) % base;
  }
}

int isEqual(int x, int y, int len)
{
  for (int i = 0; i < 2; i++)
  {
    long long h0 = (h[i][x + len] - h[i][x] + BASE[i]) * pw[i][y] % BASE[i];
    long long h1 = (h[i][y + len] - h[i][y] + BASE[i]) * pw[i][x] % BASE[i];
    if (h0 != h1)
      return 0;
  }
  return 1;
}

int check(int len0, int len1)
{
  int first0 = -1, first1 = -1;
  for (int i = 0, id = 0; i < s.size(); i++)
    if (s[i] == '0')
    {
      if (first0 < 0) first0 = id;
      else if (!isEqual(first0, id, len0)) return 0;
      id += len0;
    }
    else
    {
      if (first1 < 0) first1 = id;
      else if (!isEqual(first1, id, len1)) return 0;
      id += len1;
    }

  if (len0 == len1 && isEqual(first0, first1, len0))
    return 0;
  return 1;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> s >> t;
  n = t.size();
  t = " " + t;
  for (int i = 0; i < 2; i++)
    initHash(h[i], pw[i], P[i], BASE[i]);

  int cnt0 = 0;
  for (char c : s)
    cnt0 += c == '0';
  int cnt1 = s.size() - cnt0, ans = 0;
  for (int i = 1; i * cnt0 < n; i++)
  {
    int rem = n - i * cnt0;
    if (rem % cnt1)
      continue;
    int j = rem / cnt1;
    ans += check(i, j);
  }

  cout << ans << endl;
}