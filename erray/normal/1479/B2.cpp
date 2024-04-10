// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }

  int tn = n;
  a.resize(n = int(unique(a.begin(), a.end()) - a.begin()));

  vector<int> lst(tn, -1);
  vector<int> dp(n + 1);
  for (int i = 0; i < n; ++i) {
    if (lst[a[i]] != -1) {
      dp[i] = max(dp[i], dp[lst[a[i]] + 1] + 1);
    }  

    dp[i + 1] = dp[i];
    lst[a[i]] = i;
  }

  cout << n - dp.back() << '\n';

}