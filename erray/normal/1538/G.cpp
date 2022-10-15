// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if (x > y) {
      swap(x, y);
    }
    if (a > b) {
      swap(a, b);
    }
    int diffab = b - a;
    int diffxy = y - x;
    if (diffab == 0) {
      cout << x / a << '\n';
      continue;
    }
    int sub = min({diffxy / diffab, x / a, y / b});
    x -= a * sub;
    y -= b * sub;
    int sum = a + b;
    int more = x / sum;
    x -= more * sum;
    y -= more * sum;    
    cout << sub + more * 2 + (x >= a && y >= b) << '\n';
  }
}