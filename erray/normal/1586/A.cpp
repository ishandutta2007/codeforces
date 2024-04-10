// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int odd = -1;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] % 2 == 1) {
        odd = i;
      }
    }

    int sum = accumulate(a.begin(), a.end(), 0LL);
    bool ok = false;
    for (int i = 2; i * i <= sum; ++i) {
      ok |= (sum % i == 0);
    }

    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 0);
    if (!ok) {
      ans.erase(ans.begin() + odd);
    }
    cout << int(ans.size()) << '\n';
    for (auto e : ans) {
      cout << e + 1 << ' ';
    }
    cout << '\n';
  }
}