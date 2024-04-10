#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 10000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  for(cin >> t; t; t -= 1){
    int n;
    cin >> n;
    vector<pair<int, int>> vp;
    for(int i = 1, x; i <= n; i += 1){
      cin >> x;
      vp.push_back({x, i});
    }
    sort(vp.begin(), vp.end());
    vector<int> ans;
    LL sum = 0;
    for(auto [x, y] : vp){
      if(sum < x) ans.clear();
      sum += x;
      ans.push_back(y);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int x : ans) cout << x << " ";
    cout << "\n";
  }
  return 0;
}