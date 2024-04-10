// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 500005 /*rem*/
#define mod 31607
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T> bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}

using namespace std;

ll ksm(ll a, ll b) {
  if (!b)
    return 1;
  ll ns = ksm(a, b >> 1);
  ns = ns * ns % mod;
  if (b & 1)
    ns = ns * a % mod;
  return ns;
}

int n, k;
string s, t;
vector<pi> ops, opt;

void solve(string &s, vector<pi> &op) {

  auto kth = [&](int k) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
      if (s[i] == '1') {
        if (cnt == k)
          return i;
        cnt++;
      }
    return -1;
  };
  auto setop = [&](int l, int r) {
    int c = 0;
    for (int i = l; i <= r; i++)
      c += s[i] == '1';
    assert(c == k);
    reverse(s.begin() + l, s.begin() + r + 1);
    op.pb(mp(l + 1, r + 1));
    // cerr << "Rev " << l << "," << r << ":" << s << endl;
  };
  int cnt1 = 0;
  for (int i = 0; i < n; i++)
    cnt1 += s[i] == '1';
  if (k == 0)
    return;
  if (cnt1 < k)
    return;
  if (cnt1 == k) {
    setop(0, kth(k - 1));
    int a = kth(k - 1);
    string t = s;
    reverse(t.begin(), t.begin() + a + 1);
    if (t < s)
      setop(0, a);
    return;
  }
  for (int i = 0; i < cnt1 - k; i++) {
    setop(i, kth(i + k - 1));
  };
  int p = cnt1 - k - 1;
  for (int i = 0; i < k; i++) {
    if (i % 2 == 0)
      setop(kth(p), kth(p + k) - 1);
    else
      setop(kth(p) + 1, kth(p + k));
  }
  if (k % 2 == 0) {
    setop(kth(p - 1) + 1, kth(cnt1 - 2));
  } else {
    int l = kth(p - 1) + 1, r = kth(cnt1 - 1);
    for (int i = 0; i <= k; i++) {
      if (i % 2 == 0)
        setop(l, r - 1);
      else
        setop(l + 1, r);
    }
  }
}
void solve() {
  scanf("%d%d", &n, &k);
  cin >> s;
  cin >> t;
  ops.clear();
  opt.clear();
  solve(s, ops);
  solve(t, opt);
  if (s != t) {
    puts("-1");
    return;
  } else {
    printf("%d\n", (int)ops.size() + (int)opt.size());
    reverse(opt.begin(), opt.end());
    for (auto a : ops)
      printf("%d %d\n", a.fi, a.se);
    for (auto a : opt)
      printf("%d %d\n", a.fi, a.se);
  }
}
int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    solve();
  }
}