#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef __int128 i128;

int main() {
  ll A1, B1, A2, B2;
  cin >> A1 >> B1 >> A2 >> B2;
  map <ll, pair <pair <ll, ll>, int>> m;
  vector <ll> p2(63), p3(63);
  p2[0] = p3[0] = 1;
  for (int i = 1; i <= 62; i++) {
    p2[i] = p2[i - 1] * 2;
    p3[i] = p3[i - 1] * 3;
  }
  for (int da2 = 0; da2 < 63; da2++) {
    for (int da3 = 0; da3 < 31; da3++) {
      for (int db2 = 0; db2 < 63; db2++) {
        for (int db3 = 0; db3 < 31; db3++) {
          if ((p2[da3] * A1) % (p2[da2] * p3[da3]))
            continue;
          if ((p2[db3] * B1) % (p2[db2] * p3[db3]))
            continue;
          ll a1 = (i128)p2[da3] * (i128)A1 / ((i128)p2[da2] * (i128)p3[da3]);
          ll b1 = (i128)p2[db3] * (i128)B1 / ((i128)p2[db2] * (i128)p3[db3]);
          m[a1 * b1] = {{a1, b1}, da2 + da3 + db2 + db3};
        }
      }
    }
  }
  pair <int, pair <pair <ll, ll>, pair <ll, ll>>> ans = {200, {{-1, -1}, {-1, -1}}};
  for (int da2 = 0; da2 < 63; da2++) {
    for (int da3 = 0; da3 < 31; da3++) {
      for (int db2 = 0; db2 < 63; db2++) {
        for (int db3 = 0; db3 < 31; db3++) {
          if (((i128)p2[da3] * A2) % ((i128)p2[da2] * p3[da3]))
            continue;
          if (((i128)p2[db3] * B2) % ((i128)p2[db2] * p3[db3]))
            continue;
          ll a2 = (i128)p2[da3] * A2 / ((i128)p2[da2] * (i128)p3[da3]);
          ll b2 = (i128)p2[db3] * B2 / ((i128)p2[db2] * (i128)p3[db3]);
          int cnt = da2 + da3 + db2 + db3;
          if (m.find(a2 * b2) == m.end())
            continue;
          ans = min(ans, {m[a2 * b2].se + cnt, {m[a2 * b2].fi, {a2, b2}}});
        }
      }
    }
  }
  if (ans.fi == 200) {
    cout << -1;
    return 0;
  }
  cout << ans.fi << '\n';
  cout << ans.se.fi.fi << ' ' << ans.se.fi.se << '\n';
  cout << ans.se.se.fi << ' ' << ans.se.se.se << '\n';
  return 0;
}