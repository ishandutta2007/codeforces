#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int h, m;
    cin >> h >> m;
    cout << 24 * 60 - h * 60 - m << endl;
  }
}