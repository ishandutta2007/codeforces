#include <bits/stdc++.h>
using namespace std;

int n, a[100100];
set <int> s;

int main()
{
  ios::sync_with_stdio(0);
  int hasX = 0, hasY = 0, L, X, Y;
  
  cin >> n >> L >> X >> Y;
  for (int i = 0; i < n; i++) 
  {
    cin >> a[i];
    if (s.count(a[i] - X)) hasX = 1;
    if (s.count(a[i] - Y)) hasY = 1;
    s.insert(a[i]);
  }
  
  if (!hasX && !hasY) 
  {
    for (int i = 0; i < n; i++)
      if (s.count(a[i] - X - Y))
      {
        cout << 1 << endl;
        cout << a[i] - X << endl;
        return 0;
      }
      
    for (int i = 0; i < n; i++)
      if (a[i] >= Y && s.count(a[i] - Y + X))
      {
        cout << 1 << endl;
        cout << a[i] - Y << endl;
        return 0;
      }
      
    for (int i = 0; i < n; i++)
      if (a[i] + Y <= L && s.count(a[i] + Y - X))
      {
        cout << 1 << endl;
        cout << a[i] + Y << endl;
        return 0;
      }
      
    cout << 2 << endl << X << ' ' << Y << endl;
  }
  else 
  {
    cout << 2 - hasX - hasY << endl;
    if (!hasX) cout << X << ' ';
    if (!hasY) cout << Y << ' ';
  }
}