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
    set <int> s;
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        if (a[i] == a[j])
          continue;
        s.insert(abs(a[i] - a[j]));
      }
    cout << s.size() << '\n';
  }
  return 0;
}