#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

struct fenwick {
public:
  fenwick(int _n) : n(_n) {
    a.resize(n + 1);
    at.resize(n + 1);
  };
  void update(int l, int r, long long val) {
    _update(l, val, val * l);
    _update(r + 1, -val, -val * (r + 1));
  }
  long long find(int l, int r) {
    return _find(r) - _find(l - 1);
  }
private:
  void _update(int pos, long long aval, long long atval) {
    for (; pos <= n; pos |= (pos + 1)) {
      a[pos] += aval;
      at[pos] += atval;
    }
  }
  long long _find(int pos) {
    int r = pos;
    long long aval = 0, atval = 0;
    for (;pos >= 0; pos = (pos & (pos + 1)) - 1) {
      aval += a[pos];
      atval += at[pos];
    }
    return (r + 1) * aval - atval;
  }
  vector<long long> a, at;
  int n;
};

struct item {
  item(int _l, int _r, int _val) : l(_l), r(_r), val(_val) {};
  int l, r, val;
};

bool operator < (const item& a, const item& b) {
  return a.l < b.l || (a.l == b.l && a.r < b.r) || (a.l == b.l && a.r == b.r && a.val < b.val);
}

set<item> f;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  fenwick fen(n);
  for (int i = 0; i < n; ++i) {
    f.insert(item(i, i, i + 1));
  }
  while (m--) {
    int t, l, r, x;
    scanf("%d%d%d", &t, &l, &r);
    --l; --r;
    if (t == 1) {
      scanf("%d", &x);
      set<item>::iterator it = f.upper_bound(item(l, n + 5, 2000000000)), tmp;
      --it;
      while (it != f.end()) {
        if (it->l > r) break;
        if (it->l < l) {
          f.insert(item(it->l, l - 1, it->val));
        }
        if (it->r > r) {
          f.insert(item(r + 1, it->r, it->val));
        }
        fen.update(max(it->l, l), min(it->r, r), abs(x - it->val));
        tmp = it; ++it;
        f.erase(tmp);
      }
      f.insert(item(l, r, x));
    } else {
      printf("%lld\n", fen.find(l, r));
    }
  }
  return 0;
}