#include <bits/stdc++.h>
using namespace std;

int m, n, a[200200], b[200200], pre[200200];

void calcPre(int pre[], int p[])
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

int kmp(int pre[], int s[], int p[])
{
	int i = 0, j = 0, res = 0;
	while (i < m)
	{
		while (j >=0 && s[i] != p[j]) j = pre[j];
		i++; j++;
		if (j == n) 
    {
      res++;
      j = pre[j];
    }
	}
  return res;
}


int main()
{
  ios::sync_with_stdio(0);
  
  cin >> m >> n;
  
  if (n == 1)
  {
    cout << m << endl;
    return 0;
  }
  
  for (int i = 0; i < m; i++) cin >> a[i];
  m--;
  for (int i = 0; i < m; i++) a[i] = a[i + 1] - a[i];
  
  for (int i = 0; i < n; i++) cin >> b[i];
  n--;
  for (int i = 0; i < n; i++) b[i] = b[i + 1] - b[i];
  
  calcPre(pre, b);
  cout << kmp(pre, a, b) << endl;  
}