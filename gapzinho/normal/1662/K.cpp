#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long

using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
using ld =  double;
ld inf = 1;
const int mod = 998244353;
const int LOG = 32;
const ld eps = 1e-12;
int cmp (ld a, ld b = 0) {
  if (abs(a-b) < eps) return 0;
  return (a < b) ? -1 : +1;
}

ld x[3], y[3];

ld dist(ld x1, ld y1, ld x2, ld y2) {
  return hypot((x2-x1), (y2-y1));
}

ld get5(ld x1, ld y1, int i, int j, ld x2, ld y2) {
  return dist(x1, y1, x2, y2) + dist(x[i], y[i], x2, y2) + dist(x[j], y[j], x2, y2);
}

ld get4(ld x1, ld y1, int i, int j, ld x2) {
  ld A = min(y1, min(y[j], y[i])), B = max(y1, max(y[j],y[i]));
  for(int it = 0; it < 30; it++) {
    ld m1 = (A * 2 + B) / 3.0;
    ld m2 = (A + 2 * B) / 3.0;

    if(get5(x1, y1, i, j, x2, m1) > get5(x1, y1, i, j, x2, m2))
      A = m1;
    else
      B = m2;
  }
  return get5(x1, y1, i, j, x2, A);
}

ld get3(ld x1, ld y1, int i, int j) {
  // return func(point(x1, y1), point(x[i], y[i]), point(x[j], y[j]));
  ld A = min(x1, min(x[j], x[i])), B = max(x1, max(x[j],x[i]));
  for(int it = 0; it < 30; it++){
    ld m1 = (A * 2 + B) / 3.0;
    ld m2 = (A + 2 * B) / 3.0;

    if(get4(x1, y1, i, j, m1) > get4(x1, y1, i, j, m2))
      A = m1;
    else
      B = m2;
  }
  return get4(x1, y1, i, j, A);
}

ld get3(ld x1, ld y1) {
  ld ans = 0;
  for(int i = 0; i < 3; i++) {
    for(int j = i+1; j < 3; j++) {
      ans = max(ans, get3(x1, y1, i, j));
    }
  }
  // cout << "get de  " << x1 << " " << y1 << " = " << ans << endl;
  return ans;
}

ld get2(ld x1) {
  // return get3(x1, 0.4152457);
  ld A = min(y[0], min(y[1], y[2])), B = max(y[0], max(y[1], y[2]));
  for(int i = 0; i < 30; i++){
    ld m1 = (A * 2 + B) / 3.0;
    ld m2 = (A + 2 * B) / 3.0;
    // cout << "get2 " << A << " " << B << endl;

    if(get3(x1, m1) > get3(x1, m2))
      A = m1;
    else
      B = m2;
  }
  // cout << A << " " << B << endl;
  return get3(x1, A);
}

ld get1() {
  ld A = min(x[0], min(x[1], x[2])), B = max(x[0], max(x[1], x[2]));
  for(int i = 0; i < 30; i++){
    ld m1 = (A * 2 + B) / 3.0;
    ld m2 = (A + 2 * B) / 3.0;
    // cout << "get1 " << A << " " << B << endl;

    if(get2(m1) > get2(m2))
      A = m1;
    else
      B = m2;
  }
  return get2(A);
}
 
void solve() {
  for(int i = 0; i < 3; i++) {
    cin >> x[i] >> y[i];
  }

  cout << get1() << endl;
  // cout << get2(2.3842) << endl;
  // cout << get3(2.3842,0.4151) << endl;
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  // cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}