#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n, budget, ans = -1;
  
  cin >> n >> budget;
  budget *= 100;
  while (n--)
  {
    int x, y;
    cin >> x >> y;
    if (x * 100 + y <= budget)
      ans = max(ans, (100 - (x * 100 + y) % 100) % 100);    
  }
  
  cout << ans << endl;
}