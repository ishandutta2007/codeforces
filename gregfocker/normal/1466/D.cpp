#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

const int N = (int) 1e5 + 7;
int n;
int a[N];
int d[N];



signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      d[i] = 0;
    }
    int sol = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sol += a[i];
    }
    for (int i = 1; i < n; i++) {
      int x, y;
      cin >> x >> y;
      d[x]++;
      d[y]++;
    }
    vector<int> add;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < d[i]; j++) {
        add.push_back(a[i]);
      }
    }
    sort(add.begin(), add.end());
    add.push_back(0);
    reverse(add.begin(), add.end());
    for (int it = 0; it < n - 1; it++) {
      sol += add[it];
      cout << sol << " ";
    }
    cout << "\n";
  }

}