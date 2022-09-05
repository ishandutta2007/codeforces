#include <bits/stdc++.h>

#define sz(x) ((int) (x).size())
typedef long long ll;
typedef long double ld;

using namespace std;

int t, n, b[20];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= 10; i++)
      b[i] = 0;
    for (int i = 0; i < n; i++) {
      int d, cb;
      cin >> cb >> d;
      b[d] = max(b[d], cb);
    }
    int c = 0, r = 0;
    for (int i = 1; i <= 10; i++)
      c += b[i] > 0, r += b[i];
    if (c < 10)
      cout << "MOREPROBLEMS\n";
    else
      cout << r << "\n";
  }
}