#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

const int inf = 2000000000;

int arr[100005];
pair<int, int> mx[400005];


void build(int i, int l, int r) {
  if (l == r) {
    mx[i] = make_pair(arr[l], l);
    return;
  }
  int m = (l + r) >> 1;
  build(2 * i, l, m);
  build(2 * i + 1, m + 1, r);
  mx[i] = max(mx[2 * i], mx[2 * i + 1]);
}

pair<int, int> find(int i, int l, int r, int L, int R) {
  if (l == L && r == R)
    return mx[i];
  int m = (l + r) >> 1;
  if (R <= m) return find(2 * i, l, m, L, R);
  if (L > m) return find(2 * i + 1, m + 1, r, L, R);
  return max(find(2 * i, l, m, L, m), find(2 * i + 1, m + 1, r, m + 1, R));
}

void set_val(int i, int l, int r, int pos, int val) {
  if (l == r) {
    mx[i] = make_pair(val, l);
    return;
  }
  int m = (l + r) >> 1;
  if (pos <= m) set_val(2 * i, l, m, pos, val);
  else set_val(2 * i + 1, m + 1, r, pos, val);
  mx[i] = max(mx[2 * i], mx[2 * i + 1]);
}

long long fen[100005];

void upd(int pos, int val) {
  for (; pos <= 100000; pos |= (pos + 1))
    fen[pos] += val;
}

long long find(int pos) {
  long long ret = 0;
  for ( ; pos >= 0; pos = (pos & (pos + 1)) - 1)
    ret += fen[pos];
  return ret;
}

long long get(int l, int r) {
  return find(r) - find(l - 1);
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    upd(i, arr[i]);
  }
  // cout << n << endl;
  build(1, 0, n - 1);
  while (m--) {
    int t, l, r, x;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d", &l, &r);
      --l; --r;
      printf("%lld\n", get(l, r));
    } else if (t == 2) {
      scanf("%d%d%d", &l, &r, &x);
      --l; --r;
      while (true) {
        auto top = find(1, 0, n - 1, l, r);
        if (top.first >= x) {
          set_val(1, 0, n - 1, top.second, top.first % x);
          upd(top.second, -(top.first - top.first % x));
        } else {
          break;
        }
      }
    } else {
      scanf("%d%d", &l, &x);
      --l; r = l;
      set_val(1, 0, n - 1, l, x);
      long long cur = get(l, l);
      upd(l, -cur + x);
    }
  }
  return 0;
}