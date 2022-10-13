#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q;
  cin >> q;
  while (q--)
  {
    int n;
    cin >> n;
    cout << (n == 2 ? 2 : n % 2) << '\n';
  }
}