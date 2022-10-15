// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    string x(a, '0');
    string y(b, '0');
    x[0] = y[0] = '1';
    int p = 1;
    int left = min(a, b) - c;
    while (left--) {
      (a < b ? x : y)[p++] = '1';
    }
    cout << x << ' ' << y << '\n';
  }
}