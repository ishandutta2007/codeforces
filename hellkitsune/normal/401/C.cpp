#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

string s;

int main()
{
  int n, m;
  cin >> n >> m;
  if ((m > (n + 1) * 2) || (n > m + 1)) {
    cout << -1 << endl;
    return 0;
  }
  s.resize(n + m);
  int ind = 0;
  while (m | n) {
    if (m > n) {
      s[ind++] = '1';
      --m;
      if (m) {
        s[ind++] = '1';
        --m;
      }
      if (n) {
        s[ind++] = '0';
        --n;
      }
    } else if (m == n) {
      s[ind++] = '1';
      s[ind++] = '0';
      --m;
      --n;
    } else {
      s[ind++] = '0';
      --n;
    }
  }
  cout << s << endl;
  return 0;
}