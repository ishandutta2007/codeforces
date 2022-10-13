#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  long long n;
  cin >> n;
  long long ans = n / 2;
  if (n % 2) ans -= n;
  cout << ans << endl;
}