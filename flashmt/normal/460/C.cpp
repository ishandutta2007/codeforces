#include <bits/stdc++.h>
using namespace std;

int a[100100], s[100100], n, m, w;

int main()
{
  ios::sync_with_stdio(0);
  cin >> n >> m >> w;
  for (int i = 0; i < n; i++) cin >> a[i];
  
  int low = 0, high = int(1e9 + 1e5), ans = 0;
  while (low <= high)
  {
    int mid = (low + high) / 2, ok = 1, daysLeft = m;
    for (int i = 0; i <= n; i++) s[i] = 0;
    
    for (int i = 0; i < n; i++)
    {
      s[i] += s[i - 1];
      int curA = a[i] + s[i];
      if (curA < mid) 
      {
        int need = mid - curA;
        if (need > daysLeft)
        {
          ok = 0;
          break;
        }
        
        daysLeft -= need;
        s[i] += need;
        s[min(n, i + w)] -= need;
      }
    }
    
    if (ok) ans = mid, low = mid + 1;
    else high = mid - 1;
  }
  
  cout << ans << endl;
}