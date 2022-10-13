#include <bits/stdc++.h>
using namespace std;

int m, n, BASE, col[555], cnt[3];
long long f[555][555];

int main()
{
  ios::sync_with_stdio(0);
  string s;
  cin >> n >> m >> BASE;
  for (int i = 0; i < m; i++)
  {
    cin >> s;
    for (int j = 0; j < n; j++) col[j] += s[j] - '0';
  }
  
  for (int i = 0; i < n; i++) cnt[col[i]]++;
  
  f[m][cnt[0]] = 1;
  for (int i = m + 1; i <= n; i++)
  {
    int numOne = i * 2;
    for (int cnt0 = 0; cnt0 <= cnt[0]; cnt0++)      
    {
      int cnt2 = numOne - (n - cnt0);
      if (cnt2 < 0 || cnt2 > n) continue;
      int cnt1 = numOne - cnt2 * 2;
      if (cnt1 < 0 || cnt1 > n) continue;
      
      if (cnt1 >= 2) f[i][cnt0] = f[i - 1][cnt0 + 2] * (cnt0 + 2) * (cnt0 + 1) / 2;
      f[i][cnt0] += f[i - 1][cnt0] * (cnt1 + 2) * (cnt1 + 1) / 2;
      f[i][cnt0] += f[i - 1][cnt0 + 1] * (cnt0 + 1) * cnt1;
      f[i][cnt0] %= BASE;
    }
  }
      
  cout << f[n][0] << endl;
}