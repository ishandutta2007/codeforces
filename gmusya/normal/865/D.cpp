#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  multiset <int> s;
  ll ans = 0;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
    s.insert(a[i]);
    ans += a[i] - *s.begin();
    s.erase(s.begin());
  }
  cout << ans;
  return 0;
}