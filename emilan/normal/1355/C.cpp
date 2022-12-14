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

using ll = long long;
//#define int ll
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
#define mp(x, y)  make_pair(x, y);
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second

ll mod(1000000007);
double pi(acos(-1.0));

int main() {
  ioThings();

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int len = 1000001;
  vi cnt(len);
  int i = a + b;
  for (;;) {
    int p = i - a;
    if (p > c) break;
    cnt[i] = max(0, min(b - a + 1, p - b + 1));
    i++;
  }

  while (i <= b + c) {
    int p = i - c;
    cnt[i] = max(0, min(b - p + 1, c - b + 1));
    i++;
  }

  ll ret = 0;
  for (int i = c + 1; i <= b + c; i++) {
    ret += 1ll * cnt[i] * (min(i - 1, d) - c + 1);
  }

  cout << ret;

  return 0;
}