#include <iostream>
#include <vector>
#include <algorithm>
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
    for (int i = 0; i < n; i++)
      cin >> a[i];
    set <int> s;
    for (int i = 1; i < n; i++)
      if (a[i] <= a[i - 1])
        a[i]++;
    for (int i = 0; i < n; i++)
      s.insert(a[i]);
    cout << s.size() << '\n';
  }
  return 0;
}