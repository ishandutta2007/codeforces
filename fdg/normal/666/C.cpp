#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int mod = 1000000007;

int mPow(int a, int x) {
  int ret = 1;
  while (x > 0) {
    if (x & 1) ret = 1LL * ret * a % mod;
    a = 1LL * a * a % mod;
    x >>= 1;
  }
  return ret;
}

int inv(int x) {
  return mPow(x, mod - 2);
}

int fact[200005], rfact[200005], pw25[200005], pw26[200005];

int C(int n, int k) {
  if (k > n || k < 0) return 0;
  return 1LL * fact[n] * rfact[k] % mod * rfact[n - k] % mod;
}

struct item {
  int len, d, id;
};

bool operator < (const item &a, const item &b) {
  return a.len < b.len || a.len == b.len && a.d < b.d;
}

char s[100005];

vector<item> q;
int ans[200005];

int main() {
  int n;
  scanf("%d\n", &n);
  gets(s);
  int len = strlen(s);
  for (int i = 0; i < n; ++i) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      scanf(" %s\n", s);
      len = strlen(s);
    } else {
      int k;
      scanf("%d", &k);
      q.push_back({len, k, (int) q.size()});
    }
  }
  sort(q.begin(), q.end());

  fact[0] = rfact[0] = pw25[0] = pw26[0] = 1;
  for (int i = 1; i <= 200000; ++i) {
    fact[i] = 1LL * fact[i - 1] * i % mod;
    rfact[i] = inv(fact[i]);
    pw25[i] = 25LL * pw25[i - 1] % mod;
    pw26[i] = 26LL * pw26[i - 1] % mod;
  }

  for (int i = 0; i < q.size(); ) {
    int st = i;
    int clen = q[st].len, cnt = 1;
    while (i < q.size() && q[i].len == q[st].len) {
      if (q[i].d < clen) {
        ans[q[i].id] = 0;
      } else {
        while (q[i].d > clen) {
          cnt = (26LL * cnt + 1LL * pw25[clen + 1 - q[i].len] * C(clen, q[i].len - 1) % mod) % mod;
          ++clen;
          // cout << clen << " " << cnt << endl;
        }
        ans[q[i].id] = cnt;
      }
      ++i;
    }
  }

  for (int i = 0; i < q.size(); ++i)
    printf("%d\n", ans[i]);

  return 0;
}