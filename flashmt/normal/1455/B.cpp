#include <bits/stdc++.h>
using namespace std;

int main()
{
  int test;
  cin >> test;
  while (test--)
  {
    int n, k = 0;
    cin >> n;
    while (k * (k + 1) / 2 < n)
      k++;
    cout << k + (k * (k + 1) / 2 == n + 1) << endl;
  }
}