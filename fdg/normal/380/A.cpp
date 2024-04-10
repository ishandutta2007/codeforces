#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

// struct item {
//   item(long long _l, long long _r, int _pref, int _c, int _val = -1) : l(_l), r(_r), pref(_pref), c(_c), val(_val) {};
//   int val;
//   long long l, r;
//   int pref, c;
// };

vector<int> v;
long long len[100005];
int t[100005], l[100005], c[100005];

int main() {
  v.reserve(100000);
  int q, n;
  scanf("%d", &n);
  long long L = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &t[i], &l[i]);
    if (t[i] == 1) {
      if (v.size() < 100000) {
        v.push_back(l[i]);
      }
      ++L;
    } else {
      scanf("%d", &c[i]);
      L += 1LL * l[i] * c[i];
      for (int e = 0; e < c[i]; ++e) {
        if (v.size() == 100000) break;
        for (int j = 0; j < l[i]; ++j) {
          if (v.size() == 100000) break;
          v.push_back(v[j]);
        }
      }
    }
    len[i] = L;
  }
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    long long x;
    scanf("%I64d", &x);
    int pos = lower_bound(len, len + n, x) - len;
    if (t[pos] == 1) {
      printf("%d\n", l[pos]);
    } else {
      long long start = len[pos - 1] + 1;
      int val = v[(x - start) % l[pos]];
      printf("%d\n", val);
    }
  } 
  return 0;
}