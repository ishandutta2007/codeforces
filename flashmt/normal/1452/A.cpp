#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int x, y;
    cin >> x >> y;
    cout << max(x, y) * 2 - (x != y) << endl;
  }
}