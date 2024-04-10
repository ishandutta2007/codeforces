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

  int n; cin >> n;
  map<int, int> last, res;
  int invalid = 0;
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    if (last.count(a)) {
      if (last[a] == -1) continue;
      int d = i - last[a];
      if (res.count(a)) {
        if (res[a] != d) {
          invalid++;
          last[a] = -1;
          continue;
        }
      } else res[a] = d;
    }
    last[a] = i;
  }

  cout << sz(last) - invalid << '\n';
  for (auto& i : last)
    if (i.se != -1) cout << i.fi << ' ' << res[i.fi] << '\n';

  return 0;
}