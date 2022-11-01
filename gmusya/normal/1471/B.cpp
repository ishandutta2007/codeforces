#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector <pair <ll, ll>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = 1;
    }
    ll res = 0;
    int i = 0;
    while (i < (int)a.size()) {
      if (a[i].first % x)
        break;
      res += a[i].first * a[i].second;
      a.push_back({a[i].first / x, a[i].second * x});
      i++;
    }
    while (i < (int)a.size()) {
      res += a[i].first * a[i].second;
      i++;
    }
    cout << res << '\n';
  }
  return 0;
}