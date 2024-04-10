#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector <char> c(n);
    for (int i = 0; i < n; i++)
      cin >> c[i];
    vector <bool> skipped(n);
    vector <bool> can(n);
    for (int i = 0; i + 1 < n; i++)
      if (c[i] == c[i + 1])
        can[i] = true;
    int ans = 0;
    int del = 0;
    int pos = 0;
    while (del < n) {
      ans++;
      while (pos < del || (pos < n && !can[pos]))
        pos++;
      if (pos < n && can[pos])
        skipped[pos++] = true;
      else
        del++;
      while (del < n && (c[del] == c[del + 1]))
        del++;
      del++;
      while (skipped[del])
        del++;
    }
    cout << ans << '\n';
  }
  return 0;
}