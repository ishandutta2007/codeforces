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
    for (int i = 0; i < n; i++)
      cout << (8 + abs(i - 1)) % 10;
    cout << endl;
  }
}