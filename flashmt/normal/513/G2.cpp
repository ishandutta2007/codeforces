#include <bits/stdc++.h>
using namespace std;

int p[33], n, k;
double f[222][33][33];

int get(int i, int l, int r)
{
  if (l <= i && i <= r) return r + l - i;
  return i;
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      f[0][i][j] = p[i] > p[j];
      
  for (int turn = 1; turn <= k; turn++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int l = 0; l < n; l++)
          for (int r = l; r < n; r++)
            f[turn][i][j] += f[turn - 1][get(i, l, r)][get(j, l, r)] * 2 / n / (n + 1);
            
  double ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      ans += f[k][i][j]; 
      
  cout << fixed << setprecision(12) << ans << endl;
}