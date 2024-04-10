#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  long long r, g, b;
  cin >> r >> g >> b;
  
  long long ans = (r + g + b) / 3;
  ans = min(ans, r + g);
  ans = min(ans, g + b);
  ans = min(ans, r + b);
  
  cout << ans << endl;
}