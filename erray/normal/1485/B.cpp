// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q, k;
  cin >> n >> q >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  auto Get = [&](int x) {
    if (x == -1) {
      return 0;
    }
    
    if (x == n) {
      return k + 1;
    }

    return a[x];
  };
  
  vector<long long> pref(n + 1);
  for (int i = 0; i < n; ++i) {
    pref[i + 1] = pref[i] + Get(i + 1) - Get(i - 1) - 2;
  }


  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    cout << pref[r + 1] - pref[l] + (Get(l - 1) - 0) + (k + 1 - Get(r + 1)) << '\n';
  }
}