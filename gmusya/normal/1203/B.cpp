#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector <int> cnt(1e4 + 1);
    for (int i = 0; i < 4 * n; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    bool flag = false;
    for (int i = 0; i <= 1e4; i++) {
      if (cnt[i] % 2)
        flag = true;
      cnt[i] /= 2;
    }
    if (flag) {
      cout << "NO\n";
      continue;
    }
    int itl = 0, itr = 1e4;
    vector <int> ans;
    while (itl <= itr) {
      while (itl <= itr && !cnt[itl])
        itl++;
      while (itl <= itr && !cnt[itr])
        itr--;
      if (!cnt[itl] || !cnt[itr])
        break;
      ans.push_back(itl * itr);
      cnt[itl]--, cnt[itr]--;
    }
    sort(ans.begin(), ans.end());
    if (ans[0] == ans.back())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}