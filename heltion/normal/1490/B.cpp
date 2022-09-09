#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  for(cin >> t; t; t -= 1){
    int n, c[3] = {};
    cin >> n;
    for(int i = 0, x; i < n; i += 1){
      cin >> x;
      c[x % 3] += 1;
    }
    int ans = 0;
    while(true){
      int ok = 1;
      for(int i = 0; i < 3; i += 1) if(c[i] > n / 3){
        ok = 0;
        ans += c[i] - n / 3;
        c[(i + 1) % 3] += c[i] - n / 3;
        c[i] = n / 3;
      }
      if(ok) break;
    }
    cout << ans << "\n";
  }
  return 0;
}