#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    set <int> allx;
    vector <int> p_min(n);
    for (int i = 1; i <= n; i++) {
      allx.insert(i);
    }
    for (int i = 0; i < n; i++) {
      if (i == 0 || (a[i] != a[i - 1])) {
        p_min[i] = a[i];
      } else {
        p_min[i] = *allx.begin();
      }
      allx.erase(p_min[i]);
    }
    vector <int> p_max(n);
    for (int i = 1; i <= n; i++) {
      allx.insert(i);
    }
    for (int i = 0; i < n; i++) {
      if (i == 0 || (a[i] != a[i - 1])) {
        p_max[i] = a[i];
      } else {
        p_max[i] = *(--allx.lower_bound(a[i]));
      }
      allx.erase(p_max[i]);
    }
    for (int x : p_min) {
      cout << x << ' ';
    }
    cout << '\n';
    for (int x : p_max) {
      cout << x << ' ';
    }
    cout << '\n';
  }
  return 0;
}