#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int fen[100005];

void upd(int pos, int val) {
  for ( ; pos <= 100002; pos |= (pos + 1))
    fen[pos] += val;
}

int fnd(int pos) {
  int ret = 0;
  for ( ; pos >= 0; pos = (pos & (pos + 1)) - 1)
    ret += fen[pos];
  return ret;
}

int get(int l, int r) {
  return fnd(r) - fnd(l);
}

int get(int i) {
  return fnd(i) - fnd(i - 1);
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  int t, l, r;
  for (int i = 1; i <= n; ++i)
    upd(i, 1);
  int L = 1, R = n, rev = 0;
  while (q--) {
    scanf("%d%d", &t, &l);
    if (t == 1) {
      int nrev = rev;
      if (l > R - L + 1 - l)
        nrev = rev ^ 1;
      if (rev) {
        l = R - L + 1 - l;
      }
      rev = nrev;
      if (l <= R - L + 1 - l) {
        int pos = L + l;
        for (int i = L + l - 1; i >= L; --i, ++pos) {
          upd(pos, get(i));
          upd(i, -get(i));
        }
        L = L + l;
      } else {
        int pos = L + l - 1;
        for (int i = L + l; i <= R; ++i, --pos) {
          upd(pos, get(i));
          upd(i, -get(i));
        }
        R = L + l - 1;
      }
    } else {
      scanf("%d", &r);
      if (rev) {
        l = R - L + 1 - l;
        r = R - L + 1 - r;
        swap(r, l);
      }
      printf("%d\n", get(L + l - 1, L + r - 1));
    }
    // cout << L << "  " << R << " " << rev << endl;
    // for (int i = 1; i <= n; ++i)
    //   cout << get(i) << " ";
    // cout << endl;
  }
  return 0;
}