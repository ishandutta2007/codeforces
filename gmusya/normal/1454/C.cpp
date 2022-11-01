#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    a.resize(unique(a.begin(), a.end()) - a.begin());
    if (a.size() == 1) {
      cout << 0 << '\n';
      continue;
    }
    vector <int> cnt(n + 1, -1);
    for (int i = 0; i < (int)a.size(); i++)
      cnt[a[i]] = 0;
    for (int i = 1; i + 1 < (int)a.size(); i++)
      cnt[a[i]]++;
    for (int i = 0; i <= n; i++)
      if (cnt[i] < 0)
        cnt[i] = n + 1;
    cout << *min_element(cnt.begin(), cnt.end()) + 1 << '\n';
  }
  return 0;
}