#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
int a[maxn];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //a = p * (b + 1)
  //p < b
  int t;
  for(cin >> t; t; t -= 1){
    int x, y;
    LL ans = 0;
    cin >> x >> y;
    for(int p = 1; p < min(x / p - 1, y); p += 1) ans += min(x / p - 1, y) - p;
    cout << ans << "\n";
  }
  return 0;
}