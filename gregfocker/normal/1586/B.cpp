#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = (int) 1e5 + 7;
int n, m, a[N], b[N], c[N];
bool e[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      e[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
      cin >> a[i] >> b[i] >> c[i];
      e[b[i]] = 1;
    }
    int root = 1;
    while (e[root]) {
      root++;
    }
    for (int i = 1; i <= n; i++) {
      if (i != root) {
        cout << i << " " << root << "\n";
      }
    }
  }


  return 0;
}