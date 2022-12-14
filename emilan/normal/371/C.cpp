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

struct Ingredient {
  int have, price, need;
};

int main() {
  ioThings();

  string s; cin >> s;
  vector<Ingredient> ing(3);
  for (int i = 0; i < 3; i++)
    cin >> ing[i].have;
  for (int i = 0; i < 3; i++)
    cin >> ing[i].price;
  ll r; cin >> r;

  ing[0].need = count(all(s), 'B');
  ing[1].need = count(all(s), 'S');
  ing[2].need = count(all(s), 'C');

  ll lo = 0, hi = 1e13;
  while (lo < hi) {
    ll m = lo + (hi - lo + 1) / 2;
    ll p = 0;
    for (int i = 0; i < 3; i++) {
      p += max(m * ing[i].need - ing[i].have, 0ll) * ing[i].price;
    }

    if (p > r)
      hi = m - 1;
    else
      lo = m;
  }

  cout << lo;


  return 0;
}