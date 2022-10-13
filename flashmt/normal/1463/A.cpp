#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int a, b, c;
    cin >> a >> b >> c;
    int sum = a + b + c;
    if (sum % 9 || sum / 9 > min({a, b, c})) cout << "NO" << endl;
    else cout << "YES" << endl;
  }
}