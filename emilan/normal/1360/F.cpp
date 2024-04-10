#include <bits/stdc++.h>
using namespace std;

// #define int ll
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n) for (int i = 0; i < n; i++)
#define dotc()    int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)     (int)x.size()
#define eb        emplace_back
#define pb        push_back
#define mp        make_pair
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second

ll mod(1000000007);
double pi(acos(-1.0));

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif

  dotc() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    vector<map<char, si>> ch(m);
    rep(i, m) {
      rep(j, n) {
        ch[i][s[j][i]].insert(j);
      }
    }

    string ret;
    queue<pair<string, int>> q;
    q.emplace("", 0);
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();

      if (sz(cur.fi) == m) {
        ret = cur.fi;
        break;
      }

      for (auto i : ch[sz(cur.fi)]) {
        auto temp(cur);
        bool ok = true;
        rep(j, n) {
          if (i.se.count(j)) continue;
          if (temp.se >> j & 1) {
            ok = false;
            break;
          }
          else temp.se |= 1 << j;
        }
        if (!ok) continue;
        temp.fi.pb(i.fi);
        q.push(temp);
      }
    }

    if (!ret.empty()) cout << ret << '\n';
    else cout << "-1\n";
  }

  return 0;
}