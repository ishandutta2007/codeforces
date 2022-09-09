#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 1000;
int log(int b, int a){
  int r = 0;
  for(; a; a /= b) r += 1;
  return r;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  for(cin >> t; t; t -= 1){
    int a, b, ans = 0;
    cin >> a >> b;
    if(b == 1){
      b += 1;
      ans += 1;
    }
    for(; log(b, a) >= log(b + 1, a) + 1; b += 1) ans += 1;
    cout << ans + log(b, a) << "\n";
  }
  return 0;
}