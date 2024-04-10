#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n, a[100100], b[100100];
  cin >> n;
  for (int i = 0; i < n - 1; i++)
    cin >> a[i];
  for (int i = 0; i < n - 1; i++)
    cin >> b[i];
    
  int f[100100][4] = {0};
  for (int j = 0; j < 4; j++)
    f[0][j] = 1;
    
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < 4; j++)
      if (f[i][j])
        for (int k = 0; k < 4; k++)
          if ((j | k) == a[i] && (j & k) == b[i])
            f[i + 1][k] = 1;
            
  for (int k = 0; k < 4; k++)
    if (f[n - 1][k])
    {
      cout << "YES" << endl;
      vector<int> ans(1, k);
      for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j < 4; j++)
          if ((j | k) == a[i] && (j & k) == b[i] && f[i][j])
          {
            ans.push_back(j);
            k = j;
            break;
          }
      for (int i = n - 1; i >= 0; i--)
        cout << ans[i] << ' ';
      return 0;
    }
  
  cout << "NO" << endl;
}