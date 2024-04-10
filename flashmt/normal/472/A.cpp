#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  if (n % 2) cout << 9 << ' ' << n - 9 << endl;
  else cout << 4 << ' ' << n - 4 << endl;
}