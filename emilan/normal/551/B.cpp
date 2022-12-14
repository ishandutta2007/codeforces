#include <bits/stdc++.h>
using namespace std;

#define fastio {\
  ios::sync_with_stdio(0);\
  cin.tie(0);\
}

#define file {\
  freopen("io\\in.txt", "r", stdin);\
  freopen("io\\out.txt", "w", stdout);\
  freopen("io\\err.txt", "w", stderr);\
}

#ifdef LOCAL
#define debug(args...) {\
  string _s(#args);\
  replace(_s.begin(), _s.end(), ',', ' ');\
  stringstream _ss(_s);\
  istream_iterator<string> _it(_ss);\
  debug1(_it, args);\
}

#pragma GCC diagnostic ignored "-Wunused-parameter"
void debug1(istream_iterator<string> it) {
  cerr << endl;
}
#pragma GCC diagnostic pop

template<class T, class... Args>
void debug1(istream_iterator<string> it, T a, Args... args) {
  cerr << '>' << *it << " = " << a << "; ";
  debug1(++it, args...);
}
#else
#define debug(args...)
#define cerr if (false) cerr
#endif

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
#define mt        make_tuple
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second

const int inf(0x3fffffff);
const int mod(1000000007);
const double pi(acos(-1.0));

int32_t main() {
  fastio;
#ifdef LOCAL
  file;
#endif

  string a, b, c;
  cin >> a >> b >> c;

  vi fa(26), fb(26), fc(26);
  for (char i : a) fa[i - 'a']++;
  for (char i : b) fb[i - 'a']++;
  for (char i : c) fc[i - 'a']++;

  int x = 0, y = 0;
  for (int i = 0; i <= sz(a) / sz(b); i++) {
    vi tfa(fa);
    bool ok1 = true;
    rep(j, 26) {
      tfa[j] -= fb[j] * i;
      if (tfa[j] < 0) ok1 = false;
    }

    if (!ok1) continue;

    int l = 0, r = (sz(a) - sz(b) * i) / sz(c);
    while (l < r) {
      int mi = (l + r + 1) / 2;
      bool ok2 = true;
      rep(j, 26) if (tfa[j] < fc[j] * mi) ok2 = false;

      if (ok2) l = mi;
      else r = mi - 1;
    }
    
    if (i + l > x + y) x = i, y = l;
  }

  rep(i, x) cout << b;
  rep(i, y) cout << c;
  rep(i, 26) rep(j, fa[i] - fb[i] * x - fc[i] * y) cout << char(i + 'a');

  return 0;
}