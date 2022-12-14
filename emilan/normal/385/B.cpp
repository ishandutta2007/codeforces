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

  string s; cin >> s;
  vector<int> pos;
  for (int i = 0; i < sz(s) - 3; i++) {
    if (string(s.begin() + i, s.begin() + i + 4) == "bear")
      pos.pb(i);
  }

  int cnt = 0;
  for (int i = 0; i < sz(pos); i++) {
    cnt += (pos[i] + 1) * (sz(s) - pos[i] - 3);
    if (i)
      cnt -= (pos[i - 1] + 1) * (sz(s) - pos[i] - 3);
  }

  cout << cnt;

  return 0;
}