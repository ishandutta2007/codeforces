#include <bits/stdc++.h>
using namespace std;

inline void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif
}

#define debug(x)    cerr << #x << ": <" << (x) << ">\n"
#define dotc()      int tcs; if (cin >> tcs) for (int tc = 0; tc < tcs; tc++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second
#define mod         1000000007

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  int vp, vd, t, f, c; cin >> vp >> vd >> t >> f >> c;
  if (vp >= vd) {
    cout << 0;
    return 0;
  }
  double pp = t * vp, pd = 0;
  int bi = 0;
  do {
    double ti = pp / (vd - vp);
    pd += vd * ti, pp += vp * ti;
    if (pp < c) {
      bi++;
      pp += vp * (ti + f);
      pd = 0;
    }
  } while (pp < c);

  cout << bi;

  return 0;
}