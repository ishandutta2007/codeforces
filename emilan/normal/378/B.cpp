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
  vector<int> a(n), b(n);
  rep(i, n)
    cin >> a[i] >> b[i];
  
  string sa(n, '0'), sb(n, '0');
  fill(sa.begin(), sa.begin() + n / 2, '1');
  fill(sb.begin(), sb.begin() + n / 2, '1');

  int ai = 0, bi = 0;
  rep(i, n) {
    if (a[ai] < b[bi])
      sa[ai++] = '1';
    else
      sb[bi++] = '1';
  }

  cout << sa << '\n' << sb;

  return 0;
}