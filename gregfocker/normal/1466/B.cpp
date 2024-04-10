#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 3e5 + 7;
int f[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= 2 * n + 2; i++) {
      f[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      f[x]++;
    }
    int sol = 0;
    for (int i = 1; i <= 2 * n + 2; i++) {
      if (f[i] >= 2) {
        f[i + 1]++;
      }
    }
    for (int i = 1; i <= 2 * n + 2; i++) {
      sol += (f[i] > 0);
    }
    cout << sol << "\n";
  }
}