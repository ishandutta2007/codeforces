#include <bits/stdc++.h>
using namespace std;

inline void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("io\\in.txt", "r", stdin);
  // freopen("io\\out.txt", "w", stdout);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

#define rep(i, n) for (int i = 0; i < n; i++)
#define dotc()    int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)     (int)x.size()
#define eb        emplace_back
#define pb        push_back
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second
#define mod       1000000007

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  int n; cin >> n;
  vector<int> a(n);
  rep(i, n)
    cin >> a[i];
  sort(all(a));

  int mn = 1e9;
  for (int i = 0; i < n; i++) {
    auto it = upper_bound(all(a), a[i] * 2);
    mn = min(mn, n - distance(a.begin(), it) + i);
  }

  cout << mn;

  return 0;
}