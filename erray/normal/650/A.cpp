// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<int, int> ctX, ctY;
  map<pair<int, int>, int> ct;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    ++ctX[x];
    ++ctY[y];
    ++ct[make_pair(x, y)];
  }
  long long ans = 0;

  for (auto[foo, c] : ctX) {
    ans += 1LL * (c - 1) * c / 2;  
  }

  for (auto[foo, c] : ctY) {
    ans += 1LL * (c - 1) * c / 2;  
  }

  for (auto[foo, c] : ct) {
    ans -= 1LL * (c - 1) * c / 2;  
  }
  
  cout << ans << '\n';
}