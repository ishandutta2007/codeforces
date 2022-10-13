#include <bits/stdc++.h>
using namespace std;

int a[100100], b[100100];

void modify(int a[], int &n)
{
  for (int i = 0; i < n; i++)
    if (a[i] && a[i + 1])
    {
      int v = min(a[i], a[i + 1]);
      a[i + 2] += v;
      a[i] -= v;
      a[i + 1] -= v;
      n = max(n, i + 3);
    }
}

int evaluate(int len)
{
  double q = (sqrt(5) + 1) / 2, p = 1, x = 0, y = 0;
  for (int i = 0; i <= len; i++)
  {
    x += p * a[i];
    y += p * b[i];
    p *= q;
  }
  if (fabs(x - y) < 1e-8) return 0;
  return x < y ? -1 : 1;
}

int compare(int a[], int m, int b[], int n)
{
  for (int i = max(m, n) - 1; i >= 0; i--)
    if (a[i] != b[i])
    {
      int x = a[i] - b[i];
      if (abs(x) == 2) return x > 0 ? 1 : -1;
      if (i <= 3) return evaluate(i);
      if (x > 0) a[i - 1]++, a[i - 2]++;
      else b[i - 1]++, b[i - 2]++;
    }
  return 0;
}

int main()
{
  ios::sync_with_stdio(0);
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  int m = s.size();
  for (int i = 0; i < m; i++) a[i] = s[i] - '0';
  while (!a[m - 1]) m--;
  
  cin >> s;
  reverse(s.begin(), s.end());
  int n = s.size();
  for (int i = 0; i < n; i++) b[i] = s[i] - '0';
  while (!b[n - 1]) n--;
  
  if (!m && !n)
  {
    cout << "=\n";
    return 0;
  }
  
  if (!m || !n)
  {
    cout << (!m ? '<' : '>') << '\n';
    return 0;
  }
  
  modify(a, m);
  modify(b, n);

  int ans = compare(a, m, b, n);
  if (ans) cout << (ans > 0 ? '>' : '<') << '\n';
  else cout << "=\n";
}