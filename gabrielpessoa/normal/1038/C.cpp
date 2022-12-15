#include <bits/stdc++.h>
using namespace std;

const int ms = 2e5+5;
typedef long long ll;
pair<ll, int> a[ms];

int main() {
  int n;
  cin >> n;
  ll ans = 0;
  for(int i = 0; i < n+n; i++) {
    cin >> a[i].first;
    if(i < n) a[i].second = 0;
    else a[i].second = 1;
  }
  sort(a, a + n + n);
  reverse(a, a + n + n);
  for(int i = 0; i < n + n; i++) {
    if(i % 2 && a[i].second == 1) {
      ans -= a[i].first;
    }
    else if(i % 2 == 0 && a[i].second == 0) ans += a[i].first;
  }
  cout << ans << endl;
  return 0;
}