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
    map<int, int> mp;
    for(int i = 0, x; i < n; i += 1){
      cin >> x;
      mp[x] += 1;
    }
    vector<int> v;
    for(auto [x, y] : mp) v.push_back(y);
    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;
    for(int i = 0; i < v.size(); i += 1) ans = max(ans, (i + 1) * v[i]);
    cout << n - ans << "\n";
  }
  return 0;
}