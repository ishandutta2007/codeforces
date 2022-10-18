#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 1000100;

namespace Hash {
  const int H = 9973;
  
  const int mod1 = 1e9 + 3;
  const int mod2 = 999999937;

  inline int add(int a, int b, int mod) {
    return a+b >= mod ? a+b-mod : a+b;
  }
  
  inline int sub(int a, int b, int mod) {
    return a >= b ? a-b : a-b+mod;
  }
  
  inline int mul(int a, int b, int mod) {
    return llint(a)*b % mod;
  }

  static int pw1[MAX];
  static int pw2[MAX];

  void init() {
    pw1[0] = pw2[0] = 1;
    FOR(i, 1, MAX) {
      pw1[i] = mul(pw1[i-1], H, mod1);
      pw2[i] = mul(pw2[i-1], H, mod2);
    }
  }

  struct t {
    int h1, h2, len;
    friend bool operator < (const t& a, const t& b) {
      if (a.len != b.len) return a.len < b.len;
      if (a.h1 != b.h1) return a.h1 < b.h1;
      if (a.h2 != b.h2) return a.h2 < b.h2;
      return false;
    }
  };

  t empty() {
    t ret;
    ret.h1 = ret.h2 = ret.len = 0;
    return ret;
  }
  
  t append(t h, int c) {
    h.h1 = add(mul(h.h1, H, mod1), c, mod1);
    h.h2 = add(mul(h.h2, H, mod2), c, mod2);
    h.len++;
    return h;
  }

  t concat(t a, t b) {
    a.h1 = add(mul(a.h1, pw1[b.len], mod1), b.h1, mod1);
    a.h2 = add(mul(a.h2, pw2[b.len], mod2), b.h2, mod2);
    a.len += b.len;
    return a;
  }

  t chop_prefix(t a, t b) {
    a.h1 = sub(a.h1, mul(b.h1, pw1[a.len - b.len], mod1), mod1);
    a.h2 = sub(a.h2, mul(b.h2, pw2[a.len - b.len], mod2), mod2);
    a.len -= b.len;
    return a;
  }
};

char a[MAX];
char* s[MAX];
int len[MAX];

Hash::t h[MAX];

int main(void) {
  Hash::init();
  
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);

    char* cur = a;

    vector<pair<int, int>> v;
    REP(i, n) {
      s[i] = cur;
      scanf("%s", cur);
      len[i] = strlen(cur);
      cur += len[i];

      Hash::t cur = Hash::empty();
      REP(j, len[i]) {
        cur = Hash::append(cur, s[i][j]);
        h[s[i] + j - a] = cur;
      }

      v.push_back({len[i], i});
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    int mlen = v[0].first;
    int ptr = 0;

    set<Hash::t> bad;
    set<Hash::t> taken;
    for (int l = mlen; l > 0; --l) {
      while (ptr < (int)v.size() && v[ptr].first >= l) ptr++;
      REP(i, ptr) {
        int x = v[i].second;
        Hash::t first = h[s[x] - a];
        Hash::t pref = h[s[x] - a + l - 1];
        if (!bad.count(pref)) {
          taken.insert(pref);
          bad.insert(Hash::chop_prefix(pref, first));
        }
      }
    }

    printf("%d\n", (int)taken.size());
  }
  return 0;
}