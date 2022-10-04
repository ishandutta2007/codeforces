#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    int f1 = -1, f2 = -1, f3 = -1, f4 = -1, f5 = -1, f6 = -1, f7 = -1;
    int d1, d2, d3, d4, d5, d6, d7;
    cin >> d1 >> d2 >> d3 >> d4 >> d5 >> d6 >> d7;
    for (int i = 0; i <= d2; ++i) {
      for (int j = 0; j <= d3; ++j) {
        int ca1 = a1, ca2 = a2, cb1 = b1, cb2 = b2, cc1 = c1, cc2 = c2;
        ca1 -= i;
        cb1 -= i;
        ca2 -= (d2 - i);
        cb2 -= (d2 - i);
        ca1 -= j;
        cc1 -= j;
        ca2 -= (d3 - j);
        cc2 -= (d3 - j);
        auto bad = [&] () {
          return ca1 < 0 || cb1 < 0 || cc1 < 0 || ca2 < 0 || cb2 < 0 || cc2 < 0;
        };
        if (bad()) continue;
        int cn1 = min(ca1, min(cb1, min(cc1, d1)));
        int cn2 = min(ca2, min(cb2, min(cc2, d1 - cn1)));
        if (cn1 + cn2 != d1) continue;
        ca1 -= cn1;
        cb1 -= cn1;
        cc1 -= cn1;
        ca2 -= cn2;
        cb2 -= cn2;
        cc2 -= cn2;
        int d51 = min(cb1, min(cc1, d5));
        int d52 = min(cb2, min(cc2, d5 - d51));
        if (d51 + d52 != d5) continue;
        cb1 -= d51;
        cc1 -= d51;
        cb2 -= d52;
        cc2 -= d52;
        if (ca1 + ca2 >= d4 && cb1 + cb2 >= d6 && cc1 + cc2 >= d7) {
          f1 = cn1;
          f2 = i;
          f3 = j;
          f4 = min(ca1, d4);
          f5 = d51;
          f6 = min(cb1, d6);
          f7 = min(cc1, d7);
          //cout << f1 << ' ' << f2 << ' ' << f3 << ' ' << f4 << ' ' << f5 << ' ' << f6 << ' ' << f7 << endl;
          //cout << ca1 << ' ' << cb1 << ' ' << cc1 << ' ' << ca2 << ' ' << cb2 << ' ' << cc2 << endl;
        }
      }
    }
    if (f1 == -1) {
      cout << "-1\n";
    } else {
      cout << f1 << ' ' << f2 << ' ' << f3 << ' ' << f4 << ' ' << f5 << ' ' << f6 << ' ' << f7 << '\n';
    }
  }    
}