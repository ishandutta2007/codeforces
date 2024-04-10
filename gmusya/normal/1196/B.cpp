#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    vector <ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if ((sum - k) % 2) {
      cout << "NO\n";
      continue;
    }
    sum = 0;
    vector <ll> pos;
    for (int i = 0; i < n; i++) {
      if (pos.size() + 1 == k)
        break;
      sum += a[i];
      if (sum % 2) {
        pos.push_back(i + 1);
        sum = 0;
        continue;
      }
    }
    if (pos.size() + 1 == k) {
      cout << "YES\n";
      for (auto &now : pos)
        cout << now << ' ';
      cout << n << '\n';
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}