#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = (int) 1e5 + 7;
int n;
int p;
int k;
int x;
int y;
int a[N];
int pay[N];
string s;


signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ///freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> p >> k >> s >> x >> y;
    for (int i = 1; i <= n; i++) {
      a[i] = s[i - 1] - '0';
    }
    for (int i = n; i >= 1; i--) {
      pay[i] = (a[i] == 0);
      if (i + k <= n) {
        pay[i] += pay[i + k];
      }
    }
    int sol = (int) 1e18;
    for (int del = 0; del <= n; del++) {
      int rem = n - del;
      if (rem < p) {
        break;
      }
      sol = min(sol, pay[p + del] * x + y * del);
    }
    cout << sol << "\n";
  }

}