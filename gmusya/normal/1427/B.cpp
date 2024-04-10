#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int last = -INF;
    vector <int> l(n), r(n);
    for (int i = 0; i < n; i++) {
      l[i] = last;
      if (s[i] == 'W')
        last = i;
    }
    last = INF;
    for (int i = n - 1; i >= 0; i--) {
      r[i] = last;
      if (s[i] == 'W')
        last = i;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L')
        cnt++;
      else
        break;
    }
    if (cnt == n) {
      cout << max(2 * k - 1, 0) << '\n';
      continue;
    }
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == 'L')
        cnt++;
      else
        break;
    }
    set <pair <int, pair <int, int>>> se;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'W')
        continue;
      if (l[i] != -INF && r[i] != INF)
        se.insert({r[i] - l[i] - 1, {l[i], r[i]}});
    }
    int curans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'W') {
        if (i && s[i - 1] == 'W')
          curans += 2;
        else
          curans++;
      }
    }
    int cop = k;
    for (auto &now : se) {
      if (cop >= now.first)
        curans++;
      cop -= now.first;
    }
    cout << min(curans + 2 * k, 2 * n - 1) << '\n';
  }
  return 0;
}