#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test, a[3], n;
  cin >> test;
  while (test--)
  {
    cin >> a[0] >> a[1] >> n;
    a[2] = a[0] ^ a[1];
    cout << a[n % 3] << '\n';
  }
}