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
#define mp(x, y)  make_pair(x, y);
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second
#define mod       1000000007

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

vi p, ret;

int dfs(int i, int o, int d = 0) {
  if (d && i == o) ret[i] = d;
  else ret[i] = dfs(p[i], o, d + 1);
  return ret[i];
}

int main() {
  ioThings();

  dotc() {
    int n;
    cin >> n;
    p.resize(n);
    ret.resize(n);
    rep(i, n) {
      cin >> p[i];
      p[i]--;
    }

    rep(i, n) {
      if (!ret[i]) dfs(i, i);
    }

    for (int i : ret) cout << i << ' ';
    cout << '\n';
    p.clear();
    ret.clear();
  }

  return 0;
}