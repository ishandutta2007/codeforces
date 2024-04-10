#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int l, r;
    cin >> l >> r;
    cout << (l * 2 >= r + 1 ? "YES" : "NO") << endl;
  }
}