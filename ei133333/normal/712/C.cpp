#include <bits/stdc++.h>

using namespace std;

int main()
{
  int x, y;
  cin >> x >> y;

  vector< int > a(3, y);
  int ret = 0;
  while(a[0] < x || a[1] < x || a[2] < x) {
    a[0] = min(x, a[1] + a[2] - 1);
    ++ret;
    sort(begin(a), end(a));
  }
  cout << ret << endl;
}