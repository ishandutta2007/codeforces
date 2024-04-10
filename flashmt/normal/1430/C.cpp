#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    cout << "2\n";
    cout << n << ' ' << n - 1 << '\n';
    for (int i = n; i >= 3; i--)
      cout << i << ' ' << i - 2 << '\n';
  }
}