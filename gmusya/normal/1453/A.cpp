#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector <int> cnt(101);
    for (int i = 0; i < n + m; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    int ans = 0;
    for (int i = 0; i < 101; i++)
      ans += (cnt[i] == 2);
    cout << ans << '\n';
  }
  return 0;
}