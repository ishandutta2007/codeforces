#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> p(n), c(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      p[i]--;
    }
    for (int i = 0; i < n; i++)
      cin >> c[i];
    vector <int> lg(n + 1);
    int ans = n;
    vector <bool> used(n);
    for (int i = 0; i < n; i++) {
      if (used[i])
        continue;
      vector <int> arr;
      int x = i;
      do {
        used[x] = true;
        arr.push_back(x);
        x = p[x];
      } while (x != i);
      vector <int> del;
      int sz = (int)arr.size();
      for (int i = 1; i <= sz; i++) {
        if (sz % i)
          continue;
        del.push_back(i);
      }
      for (int d : del) {
        for (int i = 0; i < d; i++) {
          bool flag = true;
          vector <int> hm;
          for (int j = i; j < sz; j += d)
            hm.push_back(c[arr[j]]);
          for (int j = 0; j + 1 < (int)hm.size(); j++)
            if (hm[j] != hm[j + 1]) {
              flag = false;
              break;
            }
          if (flag)
            ans = min(ans, d);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}