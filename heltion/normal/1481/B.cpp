#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  for(cin >> t; t; t -= 1){
    int n, k, ans = -1;
    cin >> n >> k;
    vector<int> h(n);
    for(int i = 0; i < n; i += 1) cin >> h[i];
    for(int i = 1; i <= k; i += 1){
      int j = 0;
      for(; j + 1 < n; j += 1) if(h[j] < h[j + 1]) break;
      if(j == n - 1) break;
      h[j] += 1;
      if(i == k) ans = j + 1;
    }
    cout << ans << '\n';
  }
  return 0;
}