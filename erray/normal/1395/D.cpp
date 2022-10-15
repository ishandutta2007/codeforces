#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, d, m;
  cin >> n >> d >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.rbegin(), a.rend());
  vector<int> low, high;
  for (auto el : a) {
    if (el > m) high.push_back(el);
    else low.push_back(el);
  }
  vector<long long> pref(1, 0), pref2(1, 0);
  for (int i = 0; i < (int) low.size(); ++i) pref.push_back(pref.back() + low[i]);
  for (int j = 0; j < (int) high.size(); ++j) pref2.push_back(pref2.back() + high[j]);
  auto get = [&](int val) {
    int ex = (n - val), add = ex / (d + 1) + ((ex % (d + 1)) > 0);
    if (add >= (int) pref2.size()) return 0ll;
    return pref[val] + pref2[add];
  };
  long long ans = 0;
  for (int i = 0; i < (int) low.size() + 1; ++i) {
    ans = max(ans, get(i));
  }
  cout << ans << '\n';
}