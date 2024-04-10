// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

mt19937 rng(1919810);

const int N = 1005;

vector<int> a, o, e;
int b[N], _[N], n;

int main() {
  n = read();
  rep(i, 1, n) {
    b[i] = _[i] = read();
    if (b[i] & 1) o.pb(i);
    else e.pb(i);
  }
  sort(_ + 1, _ + n + 1);
  for (int i = 2; i <= n; i++) {
    if (_[i - 1] == _[i]) {
      a.pb(_[i] / 2);
      a.pb((_[i] + 1) / 2);
      for (int j = 1; j <= n; j++) {
        if (j == i - 1 || j == i) continue;
        a.pb(_[j] - a[0]);
      }
      puts("YES");
      for (auto v: a) printf("%d ", v); puts("");
      return 0;
    }
  }
  if (SZ(e) >= 3) { // three even numbers
    int x = b[e[0]], y = b[e[1]], z = b[e[2]];
    int sum = (x + y + z) / 2;
    a.pb(sum - x);
    a.pb(sum - y);
    a.pb(sum - z);
    rep(i, 3, SZ(e) - 1) a.pb(b[e[i]] - a[0]);
    rep(i, 0, SZ(o) - 1) a.pb(b[o[i]] - a[0]);
    puts("YES");
    for (auto v: a) printf("%d ", v); puts("");
    return 0;
  }
  if (SZ(o) >= 2 && SZ(e) >= 1) { // an even number + two odd numbers
    int x = b[o[0]], y = b[o[1]], z = b[e[0]];
    int sum = (x + y + z) / 2;
    a.pb(sum - x);
    a.pb(sum - y);
    a.pb(sum - z);
    rep(i, 1, SZ(e) - 1) a.pb(b[e[i]] - a[0]);
    rep(i, 2, SZ(o) - 1) a.pb(b[o[i]] - a[0]);
    puts("YES");
    for (auto v: a) printf("%d ", v); puts("");
    return 0;
  }
  int len = SZ(o);
  vector<int> finda, findb;
  vector<int> vis(len);
  bool flag = false;
  per(nums, min(40, len - 1), 2) {
    map<int, vector<int>> mp;
    int times = 30000;
    while (times--) {
      int t = nums;
      vector<int> chose;
      int csum = 0;
      while (t--) {
        int x;
        while (vis[x = rng() % len]) ;
        vis[x] = 1;
        chose.pb(x);
        csum += b[o[x]];
      }
      sort(chose.begin(), chose.end());
      for (auto v: chose) vis[v] = 0;
      if (mp.count(csum) && mp[csum] != chose) {
        finda = mp[csum];
        findb = chose;
        flag = true;
        goto end;
      }
      mp[csum] = chose;
    }
  }
  end: ;
  if (flag == false) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (auto v: finda) vis[v]++;
  for (auto v: findb) vis[v]++;
  vector<int> big, big1, big2;
  for (auto v: finda) if (vis[v] == 1) big1.pb(v); 
  for (auto v: findb) if (vis[v] == 1) big2.pb(v);
  for (int i = 0; i < SZ(big1); i++) big.pb(o[big1[i]]), big.pb(o[big2[i]]);
  a.pb(0);
  int las = 0;
  for (int i = 0; i < SZ(big) - 1; i++) a.pb(las = b[big[i]] - las);
  for (int i = 0; i < SZ(o); i++) if (vis[i] != 1) a.pb(b[o[i]]);
  for (auto v: e) a.pb(b[e[v]]);
  for (auto v: a) printf("%d ", v); puts("");
  return 0;
}