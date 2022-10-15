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
    vector<int> tmp = a;
    sort(tmp.begin(), tmp.end());
    int cur = tmp[0];
    bool ok = true;
    vector<int> nw;
    for (int i = 0; i < n; ++i) { 
      if (a[i] != tmp[i]) {
        if (a[i] % cur != 0) ok = false;
        nw.push_back(a[i] / cur);
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}