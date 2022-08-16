#include<bits/stdc++.h>
using namespace std;

int v[300][300];
int rec(int x, int y)
{
  if(x <= 0 || y <= 0) return(0);
  if(~v[x][y]) return(v[x][y]);
  return(v[x][y] = max(rec(x + 1, y - 2), rec(x - 2, y + 1)) + 1);
}

int main()
{
  int X, Y;
  cin >> X >> Y;
  memset(v, -1, sizeof(v));
  if(X == 1 && Y == 1) cout << 0 << endl;
  else cout << rec(X, Y) << endl;
}