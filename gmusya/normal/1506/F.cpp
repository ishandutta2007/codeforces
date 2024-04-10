#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair <int, int> pii;

int f(int r1, int c1, int r2, int c2) {
  int diagonal1 = r1 - c1;
  int diagonal2 = r2 - c2;
  if (diagonal1 == diagonal2) {
    if ((r1 + c1) & 1) {
      return 0;
    } else {
      return r2 - r1;
    }
  }
  if (diagonal1 & 1) {
    return (diagonal2 - diagonal1 + 1) / 2;
  } else {
    return (diagonal2 - diagonal1) / 2;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <pii> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
      cin >> a[i].second;
    }
    n++;
    a.emplace_back(1, 1);
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
      ans += f(a[i].first, a[i].second, a[i + 1].first, a[i + 1].second);
    }
    cout << ans << '\n';
  }
  return 0;
}