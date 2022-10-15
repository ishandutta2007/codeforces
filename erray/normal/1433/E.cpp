// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto fact = [&](int x, int y = 0) {
    long long res = 1;
    while (y < x) {
      ++y;      
      res *= y;
    }
    return res;
  };

  cout << fact(n, n / 2) * fact(n / 2 - 1) / n << '\n';
}