// author: erray
#include<bits/stdc++.h>
 
using namespace std;

#define double long double 

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  swap(n, m);
  double ans = 0;
  auto power = [&](double x) {
    int b = n;
    double res = 1;
    while (b > 0) {
      if (b & 1) {
        res *= x;
      }

      x *= x;
      b >>= 1;
    }
    return res;
  };
  
  double tmp = (double) 1 / m;
  double add = 0;
  for (int i = 1; i <= m; ++i) {
    ans += i * (power(add + tmp) - power(add));
    add += tmp;
  }

  cout << fixed << setprecision(5) << ans << '\n';
}