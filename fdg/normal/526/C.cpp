#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  long long c, hr, hb, wr, wb;
  cin >> c >> hr >> hb >> wr >> wb;
  if (wr == wb) {
    cout << max(hr, hb) * (c / wr) << endl;
    return 0;
  }
  long long cr = c / wr, cb = c / wb;
  long long add = 0;
  if (min(cr, cb) > 10000000) {
    int left = max(0LL, c - 10000000);
    if (hr * wb > hb * wr) {
      long long cnt = left / wr;
      add = cnt * hr;
      c -= cnt * wr;
    } else {
      long long cnt = left / wb;
      add = cnt * hb;
      c -= cnt * wb;
    }
    cr = c / wr; cb = c / wb;
  }
  long long ans = 0;
  if (cr > cb) {
    swap(cr, cb);
    swap(hr, hb);
    swap(wr, wb);
  }
  for (int i = 0; i <= cr; ++i) {
    long long v = hr * i + hb * ((c - i * wr) / wb);
    ans = max(ans, v);
  }
  cout << ans + add << endl;
  // long long l = 0, r = c / wr;
  // while (r - l > 10) {
  //   long long m1 = l + (r - l) / 3;
  //   long long m2 = r - (r - l) / 3;
  //   long long v1 = hr * m1 + hb * ((c - m1 * wr) / wb);
  //   long long v2 = hr * m2 + hb * ((c - m2 * wr) / wb);
  //   if (v1 >= v2) r = m2;
  //   else l = m1;
  // }
  // // cout << l << "  " << r << endl;
  // long long ans = max(hr * (c / wr), hb * (c / wb));
  // for (int i = l; i <= r; ++i) {
  //   long long v = hr * i + hb * ((c - i * wr) / wb);
  //   ans = max(ans, v);
  // }
  // for (int i = l; i <= r; ++i) {
  //   long long v = hr * i + hb * ((c - i * wr) / wb);
  //   // cout << v << endl;
  //   if (v == ans) {
  //     // cout << i << "  " << (c - i * wr) / wb << endl;
  //   }
  // }
  // cout << ans << endl;
  return 0;
}