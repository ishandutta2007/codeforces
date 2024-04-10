#include <bits/stdc++.h>
 
using namespace std;
 
void work() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int from = 0;
  while ((n = a.size()) >= 2 && a[n-2] > 0) {
    from = min(from, n-2);
    while (from < n-2 && a[from+1] == 0) ++from;
    while (from > 0 && a[from] > 0) --from;
    for (int i = from; i + 1 < (int)a.size(); ++i) {
      a[i] = a[i+1] - a[i];
    }
    a.pop_back();
    sort(a.begin() + from, a.end());
  }
  cout << a.back() << "\n";
}
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  for (int t = 0; t < tc; ++t) {
    work();
  }
  return 0;
}