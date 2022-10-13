#include <bits/stdc++.h>
using namespace std;
const int BASE = 1e6 + 3;

int main()
{
  int n;
  cin >> n;
  int ans = 1;
  for (int i = 1; i < n; i++)
    ans = ans * 3 % BASE;
  cout << ans << endl;
}