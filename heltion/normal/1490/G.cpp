#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 10000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  for(cin >> t; t; t -= 1){
    LL n, m, sum = 0;
    cin >> n >> m;
    vector<pair<LL, int>> v;
    for(int i = 0, a; i < n; i += 1){
      cin >> a;
      sum += a;
      if(not i or sum > v.back().first) v.push_back({sum, i});
    }
    for(int i = 0; i < m; i += 1){
      LL x;
      cin >> x;
      if(sum <= 0){
        if(x > v.back().first) cout << "-1 ";
        else cout << lower_bound(v.begin(), v.end(), make_pair(x, 0))->second << " ";
      }
      else{
        LL r = max(0LL, (x - v.back().first + sum - 1) / sum);
        cout << lower_bound(v.begin(), v.end(), make_pair(x - r * sum, 0))->second + r * n << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}