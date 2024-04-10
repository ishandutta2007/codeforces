#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    long long x;
    cin >> x;
    cout << (x > 14 && x % 14 > 0 && x % 14 <= 6 ? "YES" : "NO") << endl;
  }
}