#include <bits/stdc++.h>
using namespace std;

inline void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#define debug(x) cerr << #x << ": <" << (x) << ">\n"
#else
#define debug(x)
#endif
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

  int n;
  cin >> n;
  vi a(n);
  rep(i, n) cin >> a[i];
  int m;
  cin >> m;
  vi b(m);
  rep(i, m) cin >> b[i];
  sort(all(a));
  sort(all(b));

  int ai = 0, bi = 0, p = 0;
  while (ai < n && bi < m) {
    if (abs(a[ai] - b[bi]) < 2) {
      ai++, bi++, p++;
    } else if (a[ai] < b[bi]) ai++;
    else bi++;
  }

  cout << p;

  return 0;
}