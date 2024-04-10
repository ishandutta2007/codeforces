#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int a[200005], in[200005];

int md[500005], cnt[500005];

int main() {
  for (int i = 2; i < 500005; ++i) {
    if (md[i] == 0) {
      for (int j = i; j < 500005; j += i)
        if (md[j] == 0)
          md[j] = i;
    }
  }
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  long long ans = 0, total = 0;
  while (m--) {
    int x;
    scanf("%d", &x); --x;
    int X = x; x = a[x];
    vector<int> divs;
    while (x > 1) {
      int d = md[x];
      if (divs.size() == 0 || divs.back() != d)
        divs.push_back(d);
      // cout << d << endl;
      x /= d;
    }
    long long add = 0;
    for (int mask = 0; mask < (1<<divs.size()); ++mask) {
      int what = 1, bc = 0;
      for (int j = 0; j < divs.size(); ++j) {
        if (mask & (1<<j)) {
          what *= divs[j];
          ++bc;
        }
      }
      if (in[X]) {
        cnt[what]--;
      }
      if (bc & 1) {
        add -= cnt[what];
      } else {
        add += cnt[what];
      }
      // cout << what << " " << add << endl;
      if (!in[X]) {
        cnt[what]++;
      }
    }
    in[X] ^= 1;
    // cout << add << endl;
    if (in[X]) {
      ans += add;
      ++total;
    } else {
      ans -= add;
      --total;
    }
    // cout << total << endl;
    printf("%lld\n", ans);
  }
  return 0;
}