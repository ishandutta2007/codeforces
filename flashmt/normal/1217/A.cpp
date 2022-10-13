#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, s, i, e;
  cin >> t;
  while (t--)
  {
    cin >> s >> i >> e;
    int minStr = (s + i + e) / 2 + 1;
    cout << max(0, s + e - max(minStr, s) + 1) << endl;
  }
}