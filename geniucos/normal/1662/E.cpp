#include <bits/stdc++.h>

#define sz(x) ((int) (x).size())
typedef long long ll;
typedef long double ld;

using namespace std;

struct fenwick_tree {
  int n;
  vector<int> f;
  fenwick_tree(int n = 0): n(n), f(n + 1) {}
  void changeValue(int i, int d) {
    for (i++; i <= n; i += i & -i)
      f[i] += d;
  }
  int getSum(int i) {
    int s = 0;
    for (i++; i; i -= i & -i)
      s += f[i];
    return s;
  }
  int getSum(int l, int r) {
    return getSum(r - 1) - getSum(l - 1);
  }
};

int t, n, p[200100], ip[200100], a[200100], b[200100];
ll f[200100];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> p[i], p[i]--;
    int i1 = 0;
    while (p[i1] != 0)
      i1++;
    for (int i = 0; i < n; i++)
      ip[p[(i1 + i) % n]] = i;
    f[0] = 0;
    for (int i = 1; i < n; i++) {
      f[i] = ip[i] + (f[i - 1] / n) * n;
      while (f[i] < f[i - 1])
        f[i] += n;
      while (f[i] > f[i - 1] + n)
        f[i] -= n;
      a[i] = (int) (f[i] / n), b[i] = ip[i];
    }
    ll res = 0, sa = 0;
    fenwick_tree ft(n);
    for (int i = 0; i < n; i++) {
      res += i * (ll) a[i] - sa, sa += a[i];
      res -= ft.getSum(b[i] + 1, n);
      ft.changeValue(b[i], 1);
    }
    cout << res << "\n";
  }
}