#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  cout << (n % 2 ? 0 : 1 << n / 2) << endl;
}