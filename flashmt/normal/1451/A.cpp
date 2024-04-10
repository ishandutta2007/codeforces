#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    if (n <= 3) cout << n - 1 << endl;
    else cout << 2 + n % 2 << endl;
  }
}