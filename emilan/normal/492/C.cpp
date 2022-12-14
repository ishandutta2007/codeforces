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

#define dotc()  int tcs; if (cin >> tcs) for (int tc = 0; tc < tcs; tc++)
#define sz(x)   (int)x.size()
#define eb      emplace_back
#define pb      push_back
#define all(x)  x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi      first
#define se      second
#define mod     1000000007

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  int n, r, avg; cin >> n >> r >> avg;
  ll req = (ll)n * avg;
  map<int, ll> ess;
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    req -= a;
    ess[b] += r - a;
  }

  ll essCnt = 0;
  auto it = ess.begin();
  while (req > 0) {
    if (it->se > req) {
      essCnt += it->fi * req;
      req = 0;
    } else {
      essCnt += it->fi * it->se;
      req -= it->se;
    }
    it++;
  }

  cout << essCnt;

  return 0;
}