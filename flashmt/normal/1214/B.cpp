#include <bits/stdc++.h>
using namespace std;

int main()
{
  int b, g, n;
  cin >> b >> g >> n;
  cout << min(min(min(b, g), n), b + g - n) + 1 << endl;
}