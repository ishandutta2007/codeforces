// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<int>> s;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      s[a[i]].push_back(i);
    }
    vector<pair<int, int>> temp_ans;

    for (auto[key, val] : s) {
      val.push_back(n);                    
      auto get = [&](int x) {
        if (x < 0) return -1;
        return val[x];
      };
      int res = 0;
      for (int i = 0; i < (int) val.size(); ++i) {
        res = max(res, val[i] - get(i - 1));                           
      } 
      temp_ans.emplace_back(res, key);
    }
    sort(temp_ans.begin(), temp_ans.end());
    int p = 0;   
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
      while (p < (int) temp_ans.size() && temp_ans[p].first <= i + 1) {
        ans = min(ans, temp_ans[p].second);
        ++p;         
      }
      cout << (ans == INT_MAX ? -1 : ans) << ' '; 
    }
    cout << '\n';
  }
}