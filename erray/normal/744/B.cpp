// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  auto ask = [&](vector<int> a) {
    cout << (int) a.size() << '\n';
    for (auto i : a) {
      cout << i + 1 << ' ';
    }
    cout << endl;
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
      cin >> res[i];
    }
    return res;
  };
  
  vector<int> ans(n, (int) 1e9);
  for (int bit = 0; (1 << bit) < n; ++bit) {
    vector<vector<int>> now(2);    
    for (int i = 0; i < n; ++i) {
      now[i >> bit & 1].push_back(i);
    }
    for (int k = 0; k < 2; ++k) {
      auto res = ask(now[k]);
      for (auto ind : now[k ^ 1]) {
        ans[ind] = min(ans[ind], res[ind]);          
      }
    }
  }
  cout << -1 << endl;
  for (auto el : ans) {
    cout << el << ' ';
  }                   
  cout << endl;
}