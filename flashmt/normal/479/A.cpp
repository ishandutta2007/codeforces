#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  cout << max(max(max((a + b) * c, a * (b + c)), a * b * c), a + b + c) << endl;
}