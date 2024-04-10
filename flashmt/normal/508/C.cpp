#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int m, t, r, w, ans = 0;
  deque <int> candles;
  
  cin >> m >> t >> r;
  for (int i = 0; i < m; i++) 
  {
    cin >> w;
    while (!candles.empty() && candles.front() + t <= w)
      candles.pop_front();
      
    int need = r - candles.size();
    if (need <= 0) continue;
    
    int last = candles.empty() ? w - t : candles.back();
    if (last + need > w)
    {
      cout << -1 << endl;
      return 0;
    }
    
    for (int i = need - 1; i >= 0; i--)
      candles.push_back(w - i);
    ans += need;
  }
  
  cout << ans << endl;
}