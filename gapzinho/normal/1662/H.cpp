#include <bits/stdc++.h>
using namespace std;


#define int long long
#define endl "\n"

int i;
bool isdiv(int x, int y) {
  return x % i == 0 && y % i == 0;
}

void solve() {
  int w, l;
  cin >> w >> l;
  vector<int> ans = {2};
  for( i = 1; i*i <= l; i++) {
    if(isdiv(w-2, l) || isdiv(w, l-2) || isdiv(w-1, l-1)) ans.emplace_back(i);
    if(l % i == 0) {
      int k = i;
      i = l/i;
      if(isdiv(w-2, l) ) ans.emplace_back(i);
      i = k;
    } 
    if((l-1) % i == 0) {
      int k = i;
      i = (l-1)/i;
      if(isdiv(w-1, l-1)) ans.emplace_back(i);
      i = k;
    } 
    if((l-2) % i == 0) {
      int k = i;
      i = (l-2)/i;
      if(isdiv(w, l-2)) ans.emplace_back(i);
      i = k;
    }
  }
  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
  cout << ans.size();
  for(int x : ans) {
    cout << " "  << x;
  }
  cout << endl;
}

 main() {
  int t;
  cin >> t;
  while(t--) {
      solve();
  }
}