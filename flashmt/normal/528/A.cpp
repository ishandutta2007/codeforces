#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int X, Y, n, u;
  set <int> x, y;
  multiset <int> dx, dy;
  string t;
  
  cin >> X >> Y >> n;
  
  x.insert(0);
  x.insert(X);
  dx.insert(X);
  
  y.insert(0);
  y.insert(Y);
  dy.insert(Y);
  
  while (n--)
  {
    cin >> t >> u;
    if (t == "H")
    {
      auto i = y.lower_bound(u);
      auto j = i;
      j--;
      dy.erase(dy.find(*i - *j));
      y.insert(u);
      dy.insert(*i - u);
      dy.insert(u - *j);
    }
    else
    {
      auto i = x.lower_bound(u);
      auto j = i;
      j--;
      dx.erase(dx.find(*i - *j));
      x.insert(u);
      dx.insert(*i - u);
      dx.insert(u - *j);
    }
    
    cout << 1LL * (*dx.rbegin()) * (*dy.rbegin()) << '\n';
  }
}