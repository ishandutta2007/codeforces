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

int main() {
  ioThings();

  set<char> str{'1', '2'};

  dotc() {
    int n;
    cin >> n;

    vector<string> m(2);
    rep(i, 2) {
      cin >> m[i];
    }

    int y = 0, i;
    for (i = 0; i < n; i++) {
      if (!str.count(m[y][i])) {
        y ^= 1;
        if (str.count(m[y][i])) break;
      }
    }

    cout << (y && i == n ? "YES\n" : "NO\n"); 
  }

  return 0;
}