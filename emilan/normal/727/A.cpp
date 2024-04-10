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

  int a, b;
  cin >> a >> b;
  
  vector<int> h{b};
  while (a < b) {
    if (b % 10 == 1) b /= 10;
    else if (!(b & 1)) b /= 2;
    else break;
    h.pb(b);
  }

  if (a == b) {
    cout << "YES\n";
    cout << sz(h) << '\n';
    while (!h.empty()) {
      cout << h.back() << ' ';
      h.pop_back();
    }
  } else cout << "NO";

  return 0;
}