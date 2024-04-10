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
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, q;
  cin >> n >> q;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector <int> qr(q);
  int sz = n;
  for (int i = 0; i < q; ++i) {
    cin >> qr[i];
    if (qr[i] > 0) ++sz;
    else --sz;
  }
  if (sz == 0) {
    cout << "0\n";
    return 0;
  }
  int l = 0, r = n + 1;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] >= m) ++c2;
      else ++c1;
    }
    for (int i = 0; i < q; ++i) {
      if (qr[i] > 0) {
        if (qr[i] >= m) ++c2;
        else ++c1;
      }
      if (qr[i] < 0) {
        int id = -qr[i];
        if (id <= c1) --c1;
        else --c2;
      }   
    }
    if (c2 > 0) l = m;
    else r = m;
  }
  cout << l << '\n';
}