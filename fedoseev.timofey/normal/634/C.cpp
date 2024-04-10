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
 	
typedef long long ll;

using namespace std;	

struct Fenwick {
  int n;
  vector <int> f;
  void modify(int i, int val) {
    for (; i < n; i |= i + 1) {
      f[i] += val;
    }
  }
  void add(int l, int r, int val) {
    modify(l, val);
    if (r + 1 < n) modify(r + 1, -val);
  }
  int get(int r) {
    int res = 0;
    for (; r >= 0; r &= r + 1, --r) {
      res += f[r];
    }
    return res;
  }
  Fenwick(int nn) {
    n = nn;
    f.resize(n);
  }
};
 
int main() {	
  ios_base::sync_with_stdio(false); cin.tie(0);	
#ifdef LOCAL	
  freopen("input.txt", "r", stdin);	
#endif	
  int n, k, a, b, q;
  cin >> n >> k >> a >> b >> q;
  vector <int> have(n);
  Fenwick pref(n + 1), suf(n + 1);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int d, c;
      cin >> d >> c;
      --d;
      pref.add(d + 1, n, -min(have[d], b));
      suf.add(0, d, -min(have[d], a));
      have[d] += c;
      pref.add(d + 1, n, min(have[d], b));
      suf.add(0, d, min(have[d], a));
    } else {
      int p;
      cin >> p;
      --p;
      cout << pref.get(p) + suf.get(p + k) << '\n';
    }
  }
}