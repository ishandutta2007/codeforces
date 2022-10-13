#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;

int n, a[100100], ans[100100];
vector <int> f[100100], good[100100];

int main()
{
  ios::sync_with_stdio(0);
  
  int length = 0;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    if (!length || a[f[length].back()] < a[i]) f[++length].push_back(i);
    else
    {
      int low = 1, high = length, id = 0;
      while (low <= high)
      {
        int mid = (low + high) / 2;
        if (a[f[mid].back()] >= a[i]) id = mid, high = mid - 1;
        else low = mid + 1;
      }
      f[id].push_back(i);
    }
  }
  
  a[n + 1] = oo;
  good[length + 1].push_back(n + 1);
  for (int i = length; i; i--)
  {
    for (int j = 0; j < int(f[i].size()); j++)
    {
      int id = f[i][j];
      int low = 0, high = good[i + 1].size() - 1, found = -1;
      while (low <= high)
      {
        int mid = (low + high) / 2;
        if (a[good[i + 1][mid]] <= a[id]) high = mid - 1;
        else found = mid, low = mid + 1;
      }
      if (found >= 0 && good[i + 1][found] > id) good[i].push_back(id);
    }
    
    if (good[i].size() == 1) ans[good[i][0]] = 2;
    else
      for (int j = 0; j < int(good[i].size()); j++)
        ans[good[i][j]] = 1;
  }  
  
  for (int i = 1; i <= n; i++) cout << ans[i] + 1;
}