#include <iostream>
#include <vector>

using namespace std;

struct triple {
  int c3 = -1, c5 = -1, c7 = -1;
  triple() {};
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector <triple> ans(1001);
  for (int cnt3 = 0; 3 * cnt3 <= 1000; cnt3++)
    for (int cnt5 = 0; 5 * cnt5 + 3 * cnt3 <= 1000; cnt5++)
      for (int cnt7 = 0; 7 * cnt7 + 5 * cnt5 + 3 * cnt3 <= 1000; cnt7++) {
        int val = 7 * cnt7 + 5 * cnt5 + 3 * cnt3;
        ans[val].c3 = cnt3;
        ans[val].c5 = cnt5;
        ans[val].c7 = cnt7;
      }
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    if (ans[n].c3 == -1)
      cout << -1 << '\n';
    else
      cout << ans[n].c3 << ' ' << ans[n].c5 << ' ' << ans[n].c7 << '\n';
  }
  return 0;
}