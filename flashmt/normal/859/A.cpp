#include <bits/stdc++.h>
using namespace std;

int main()
{
  int k, mx = 0, x;
  cin >> k;
  for (int i = 0; i < k; i++)
  {
    cin >> x;
    mx = max(mx, x);
  }

  cout << max(0, mx - 25) << endl;
}