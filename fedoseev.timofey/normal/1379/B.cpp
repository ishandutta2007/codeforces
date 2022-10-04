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
  int t;
  cin >> t;
  while (t--) {
    int l, r; ll m;
    cin >> l >> r >> m;
    auto get = [&] (int sm) {
      for (int c = l; c <= r; ++c) {
        int b = sm + c;
        if (l <= b && b <= r && l <= c && c <= r) return make_pair(b, c);
      } 
      assert(false);
    };  
    int aa, ab, ac;
    for (int a = l; a <= r; ++a) {
      int _r = m % a;
      int _l = _r - a;
      if (l - r <= _l && _l <= r - l) {
        aa = a;
        auto pr = get(_l);
        ab = pr.first;
        ac = pr.second;
        break;
      }
      if (l - r <= _r && _r <= r - l) {
        aa = a;
        auto pr = get(_r);
        ab = pr.first;
        ac = pr.second;
      }
    }
    cout << aa << ' ' << ab << ' ' << ac << '\n';
  }
}