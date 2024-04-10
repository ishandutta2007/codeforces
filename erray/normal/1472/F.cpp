// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(k);
    for (int i = 0; i < k; ++i) {
      cin >> a[i].second >> a[i].first;
    }
    sort(a.begin(), a.end());

    bool ok = (k % 2 == 0);
    for (int i = 0; i < k - 1 ; i += 2) {
      ok &= ((a[i].second == a[i + 1].second) == ((a[i + 1].first - a[i].first) % 2) && (i == 0 || (a[i - 1].first != a[i].first)));
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}