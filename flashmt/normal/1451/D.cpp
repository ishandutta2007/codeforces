#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int d, k;
    cin >> d >> k;
    int x = 0;
    while (2LL * (x + k) * (x + k) <= 1LL * d * d)
      x += k;
    if (1LL * x * x + 1LL * (x + k) * (x + k) <= 1LL * d * d) cout << "Ashish" << endl;
    else cout << "Utkarsh" << endl;
  }
}