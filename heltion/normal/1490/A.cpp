#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  for(cin >> t; t; t -= 1){
    int n, x, ans = 0;
    cin >> n >> x;
    for(int i = 1, y; i < n; i += 1){
      cin >> y;
      for(int a = min(x, y) * 2, b = max(x, y); a < b; a <<= 1) ans += 1;
      x = y;
    }
    cout << ans << "\n";
  }
  return 0;
}