#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <sstream>
#include <memory.h>
#include <cmath>
#include <cstdlib>

using namespace std;

int n, s[50005], p;

vector<pair<long long, int>> bad;

struct item{
  int a1, b1, a2, b2;
};

item tree[200002];

item merge(int m, const item &l, const item & r) {
  int a1 = l.a2,
      b1 = l.b2;
  int a2 = (1LL * s[m] * l.a1 + 1LL * s[(m + 1) % n] * l.a2) % p,
      b2 = (1LL * s[m] * l.b1 + 1LL * s[(m + 1) % n] * l.b2) % p;

  item ret = {(int)((1LL * a1 * r.a1 + 1LL * a2 * r.b1) % p),
              (int)((1LL * b1 * r.a1 + 1LL * b2 * r.b1) % p),
              (int)((1LL * a1 * r.a2 + 1LL * a2 * r.b2) % p),
              (int)((1LL * b1 * r.a2 + 1LL * b2 * r.b2) % p)};

  return ret;
}

void build(int i, int l, int r) {
  if (l == r) {
    tree[i] = item{1, 0, 0, 1};
    return;
  }
  int m = (l + r) >> 1;
  build(2 * i, l, m);
  build(2 * i + 1, m + 1, r);
  tree[i] = merge(m, tree[2 * i], tree[2 * i + 1]);
}

item find(int i, int l, int r, int L, int R) {
  if (l == L && r == R) {
    // cout << "Fnd: " << i << "  " << l << " " << r << "  " << tree[i].a1 << "  " << tree[i].b1 << endl;
    return tree[i];
  }
  int m = (l + r) >> 1;
  if (R <= m)
    return find(2 * i, l, m, L, R);
  if (L > m)
    return find(2 * i + 1, m + 1, r, L, R);
  return merge(m, find(2 * i, l, m, L, m), find(2 * i + 1, m + 1, r, m + 1, R)); 
}

item mPow(item a, long long x) {
  item ret; bool was = false;
  while (x > 0) {
    if (x & 1) {
      if (!was) ret = a;
      else ret = merge(n - 1, ret, a);
      was = true;
    }
    a = merge(n - 1, a, a);
    x >>= 1;
  }
  return ret;
}

item get(long long l, long long r) {
  long long st = l - (l % n);
  while (st < l) st += n;
  long long fn = r - (r % n);
  while (fn + n <= r) fn += n;

  if (st <= fn) {
    if (n == 1)
        return mPow(find(1, 0, n - 1, 0, 0), (fn - st) / n + 1);
    if (fn > st) {
      item ret = mPow(find(1, 0, n - 1, 0, n - 1), (fn - st) / n);
      if (l % n != 0)
        ret = merge(n - 1, find(1, 0, n - 1, l % n, n - 1), ret);
      // if (r % n != n - 1)
      ret = merge(n - 1, ret, find(1, 0, n - 1, 0, r % n));
      // cout << "!!\n";
      return ret;
    } else {
      if (l % n == 0)
        return find(1, 0, n - 1, 0, r % n);
      return merge(n - 1, find(1, 0, n - 1, l % n, n - 1), find(1, 0, n - 1, 0, r % n));
    }
  }
  if (l % n > r % n && l <= r)
    exit(-1);
  return find(1, 0, n - 1, l % n, r % n);
}

// int ss[5000005];

int main() {
  // freopen("input.txt", "w", stdout);
  // cout << 100000000000LL << " " << 1000000000 << endl;
  // cout << 50000 << endl;
  // for (int i = 0; i < 50000; ++i)
  //   cout << rand() << " ";
  // cout << n << endl;
  // cout << 0 << endl;
  // return 0;


  long long k;
  scanf("%lld%d", &k, &p);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &s[i]);
    s[i] %= p;
  }
  // for (int i = 0; i <= k; ++i)
  //   ss[i] = s[i % n];
  int m;
  scanf("%d", &m);
  while (m--) {
    long long j;
    int v;
    scanf("%lld%d", &j, &v);
    if (j <= k - 1) {
      bad.push_back({j, v % p});
      // ss[j] = v % p;
    }
  }
  sort(bad.begin(), bad.end());

  build(1, 0, n - 1);

  // for (int i = 0; i < 5 * n; ++i) {
  //   for (int j = i; j < 5 * n; ++j) {
  //     int a = 1, b = 1;
  //     auto ret = get(i, j);
  //     cout << "Query: " << i << " " << j << endl;
  //     cout << (1LL * ret.a1 * a + 1LL * ret.b1 * b) % p << "  " << (1LL * ret.a2 * a + 1LL * ret.b2 * b) % p << endl;
  //     for (int t = i + 1; t <= j; ++t) {
  //       int na = b, nb = (1LL * s[(t - 1) % n] * a + 1LL * s[t % n] * b) % p;
  //       a = na; b = nb;
  //     }
  //     cout << a << "  " << b << endl;
  //   }
  // }

  if (k <= 1) {
    cout << k % p << endl;
    return 0;
  }

  int a = 0, b = 1;
  long long ind = 1;
  pair<long long, int> last = {-5, -1};

  // cout << bad.size() << endl;
  if (!bad.size() || bad.back().first != k - 1)
    bad.push_back({k - 1, s[(k - 1) % n]});
  for (auto x : bad) {
    if (last.first + 1 == x.first) {
      int na = b, nb = (1LL * last.second * a + 1LL * x.second * b) % p;
      a = na; b = nb;
      ind++;
    } else {
      // cout << "F\n";
      if (last.first != -5) {
        ind++;
        int na = b, nb = (1LL * last.second * a + 1LL * s[(ind - 1) % n] * b) % p;
        a = na; b = nb;
      }

      if (last.first + 2 < x.first) {
        long long st = (last.first == -5) ? 0 : (last.first + 1);
        if (st <= x.first - 1) {
          // cout << "Go:  " << st << " " << x.first - 1 << endl;
          item ret = get(st, x.first - 1);
          int na = (1LL * a * ret.a1 + 1LL * b * ret.b1) % p,
              nb = (1LL * a * ret.a2 + 1LL * b * ret.b2) % p;
          a = na;
          b = nb;
          ind += (x.first - 1 - st);
          // cout << ind << "  " << ret.a1 << " " << ret.b1 << "  " << ret.a2 << "  " << ret.b2 << endl;
          // cout << a << "  " << b << endl;
        } else {
          // exit(-1);
        }
      }

      {
        ind++;
        int na = b, nb = (1LL * s[(ind - 2) % n] * a + 1LL * x.second * b) % p;
        a = na; b = nb;
      }
    }
    last = x;
    // cout << a << "  " << b << " " << ind << endl;
  }

  cout << b % p << endl;

  // a = 0; b = 1;
  // for (int t = 2; t <= k; ++t) {
  //   int na = b, nb = (1LL * ss[t - 2] * a + 1LL * ss[t - 1] * b) % p;
  //   a = na; b = nb;
  //   // cout << b << endl;
  // }
  // cout << b << endl;

  return 0;
}