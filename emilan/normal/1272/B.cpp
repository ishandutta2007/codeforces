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
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

int main() {
  ioThings();

  dotc() {
    string s;
    cin >> s;

    int u = min(count(all(s), 'U'), count(all(s), 'D'));
    int r = min(count(all(s), 'R'), count(all(s), 'L'));

    if (!r) u = min(u, 1);
    if (!u) r = min(r, 1);

    string ret;
    ret += string(u, 'U');
    ret += string(r, 'R');
    ret += string(u, 'D');
    ret += string(r, 'L');
    cout << sz(ret) << '\n' << ret << '\n';
  }

  return 0;
}