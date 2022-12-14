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

#define dotc()  int tcs; if (cin >> tcs) for (int tc = 0; tc < tcs; tc++)
#define sz(x)   (int)x.size()
#define eb      emplace_back
#define pb      push_back
#define all(x)  x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi      first
#define se      second
#define mod     1000000007

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  string s; cin >> s;
  int m; cin >> m;
  map<int, int> a;
  while (m--) {
    int b; cin >> b;
    a[b - 1]++;
  }

  int cur = 0;
  for (int i = 0; i < sz(s) / 2; i++) {
    if (a.count(i))
      cur += a[i];
    if (cur % 2)
      swap(s[i], s[sz(s) - i - 1]);
  }

  cout << s;

  return 0;
}