#include <bits/stdc++.h>
using namespace std;

int main()
{
  int w, h;
  cin >> w >> h;
  long long ans = 1;
  for (int i = 0; i < w + h; i++)
    ans = ans * 2 % 998244353;
  cout << ans << endl;
}