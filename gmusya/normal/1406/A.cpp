#include <iostream>
#include <vector>

using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> cnt(101);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    int ans = 0;
    for (int i = 0; i < 101 && cnt[i]; i++)
      ans++, cnt[i]--;
    for (int i = 0; i < 101 && cnt[i]; i++)
      ans++, cnt[i]--;
    cout << ans << '\n';
  }
  return 0;
}