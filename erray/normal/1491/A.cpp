// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  } 

  int sum = accumulate(a.begin(), a.end(), 0);

  while (m--) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      sum += (a[x - 1] ? -1 : 1);
      a[x - 1] ^= 1;
    } else {
      cout << (sum >= x) << '\n';
    }
  }
}