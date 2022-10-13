#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  int a, b;
  cin >> a >> b;
  for (int i = 1; i <= a; i++) cout << i << ' ';
  for (int i = a + b + 1; i > a; i--) cout << i << ' ';
}