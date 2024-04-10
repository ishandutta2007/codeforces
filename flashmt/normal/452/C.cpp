#include <bits/stdc++.h>
using namespace std;

double f[1010][1010];

int main()
{
	ios::sync_with_stdio(0);
	int m, n;
	cin >> n >> m;
  
  f[1][1] = 1;
  for (int i = 1; i < n; i++)
    for (int j = 1; j <= min(m, i); j++)
    {
      int other = (n - 1) * m - (i - j);
      f[i + 1][j] += f[i][j] * other / (m * n - i);
      f[i + 1][j + 1] += f[i][j] * (m - j) / (m * n - i);
    }
    
  double ans = 0;
  for (int j = 1; j <= min(m, n); j++) ans += f[n][j] * j / n;
  printf("%.12lf\n", ans);
}