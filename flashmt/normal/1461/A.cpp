#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
      cout << char('a' + i % 3);
    cout << endl;
  }
}