#include <bits/stdc++.h>
using namespace std;
const int BASE = int(1e9) + 7;

int m, n, pre[1000100], match[1000100], pos[1000100];
string p;
char a[1000100];

void calcPre(int pre[], string p)
{
	int i = 0, j = -1, n = p.size();
	pre[0] = -1;
	while (i < n)
	{
		while (j >= 0 && p[i] != p[j]) j = pre[j];
		i++; j++;
		pre[i] = (j >= n || p[i] != p[j] ? j : pre[j]);
	}
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n >> m >> p;
  calcPre(pre, p);
  
  for (int i = 0; i < m; i++)
  {
    cin >> pos[i];
    match[--pos[i]] = 1;
  }
  
  for (int i = 0; i < n; i++) a[i] = '?';
  
  for (int i = 0, j = 0; i < n && j < m; i++)
  {
    if (j + 1 < m && pos[j + 1] <= i) j++;
    if (i - pos[j] < p.size()) a[i] = p[i - pos[j]];
  }
  
  for (int i = 0, j = 0; i < n; )
  {
    while (j >= 0 && a[i] != p[j]) j = pre[j];
    i++;
    j++;
    if (i >= p.size() && match[i - p.size()] && j != p.size())
    {
      cout << "0\n";
      return 0;
    }
  }
  
  long long ans = 1;
  for (int i = 0; i < n; i++)
    if (a[i] == '?')
      ans = ans * 26 % BASE;
  cout << ans << endl;
}