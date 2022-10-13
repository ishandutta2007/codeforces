#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a[3], d;
  for (int i = 0; i < 3; i++)
    cin >> a[i];
  cin >> d;
  sort(a, a + 3);
  cout << max(0, d + a[1] - a[2]) + max(0, d + a[0] - a[1]) << endl;
}