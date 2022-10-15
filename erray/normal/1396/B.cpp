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
    for (int i = 0; i < n; ++i) cin >> a[i];
    int sum = accumulate(a.begin(), a.end(), 0);
    if (*max_element(a.begin(), a.end()) > sum / 2 || sum % 2 == 1) {
      cout << 'T';    
    } else cout << "HL";
    cout << '\n';
  }
}