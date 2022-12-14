#include <bits/stdc++.h>
using namespace std;

inline void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif
}

using   ll        = long long;
#define debug(x)    cerr << #x << ": <" << (x) << ">\n"
#define dotc()      int tcs; if (cin >> tcs) for (int tc = 0; tc < tcs; tc++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second
#define mod         1000000007

int main() {
  ioThings();

  int n; cin >> n;
  set<int> s;
  while (n--) {
    int m; cin >> m;
    s.insert(m);
  }

  if (sz(s) > 3)
    cout << "NO\n";
  else if (sz(s) < 3)
    cout << "YES\n";
  else {
    if (*++(s.begin()) - *s.begin() == *s.rbegin() - *++(s.begin()))
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}