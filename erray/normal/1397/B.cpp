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
  }
  sort(a.begin(), a.end());
  if (n <= 2) return cout << a[0] - 1 << '\n', 0;
  auto Pow = [&](int x) {
    long long cur = 1;
    for (int i = 0; i < n; ++i) {
      if (cur > (long long) 1e10) return false;    
      cur *= x;  
    }  
    return true;
  };
  long long ans = LLONG_MAX;
  int db = 0;
  for (int i = 1; Pow(i); ++i) {
    db = i;
    long long tans = 0;
    long long cur = 1;
    for (auto el : a) {
      tans += abs(cur - el);
      cur *= i;
    }          
    ans = min(ans, tans);
  }
  cerr << db << '\n';
  cout << ans << '\n';
}