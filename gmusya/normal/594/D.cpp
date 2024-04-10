#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long ll;

const ll MOD = 1e9 + 7;

struct fenwick_tree {
  int n;
  vector <ll> t;
  fenwick_tree(int _n) {
    n = _n;
    t.resize(n, 1);
  }
  void upd(int pos, ll val) {
    while (pos < n) {
      t[pos] = (t[pos] * val) % MOD;
      pos |= pos + 1;
    }
  }
  ll get(int pos) {
    ll res = 1;
    while (pos != -1) {
      res = (res * t[pos]) % MOD;
      pos &= pos + 1;
      pos--;
    }
    return res;
  }
};

ll binp(ll a, ll p) {
  if (!p)
    return 1;
  if (p & 1)
    return a * binp(a, p - 1) % MOD;
  ll x = binp(a, p / 2);
  return x * x % MOD;
}

ll obr(ll x) {
  return binp(x, MOD - 2);
}

vi lp, rev;
vi a;
vvi fact;

void init() {
  vi pr;
  lp.resize(1'000'001);
  for (int i = 2; i <= 1'000'000; i++) {
    if (!lp[i]) lp[i] = i, pr.push_back(i);
    for (int j = 0; j < (int) pr.size() && pr[j] <= lp[i] && pr[j] * i <= 1'000'000; j++)
      lp[pr[j] * i] = pr[j];
  }
  rev.resize(1'000'001);
  for (int i = 1; i <= 1'000'000; i++)
    rev[i] = obr(i);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  int n;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  fact.resize(n);
  for (int i = 0; i < n; i++) {
    int x = a[i];
    while (x > 1) {
      fact[i].push_back(lp[x]);
      x /= lp[x];
    }
  }
  int q;
  cin >> q;
  vi l(q), r(q);
  for (int i = 0; i < q; i++) {
    cin >> l[i] >> r[i];
    l[i]--, r[i]--;
  }
  vi p(q);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) {
    return l[i] > l[j];
  });
  fenwick_tree ft(n);
  for (int i = 0; i < n; i++)
    ft.upd(i, a[i]);
  vvi vhozh(1'000'001);
  vi cur(1'000'001, -1);
  vvi imcap(n);
  for (int i = 0; i < n; i++)
    for (int x : fact[i]) {
      vhozh[x].push_back(i);
      if (cur[x] == -1) {
        cur[x] = i;
        imcap[i].push_back(x);
        ft.upd(i, (x - 1) * 1ll * rev[x] % MOD);
      }
    }
  vi answer(q);
  for (int i = 0; i < n; i++) {
    while (!p.empty() && l[p.back()] == i) {
      answer[p.back()] = ft.get(r[p.back()]) * (i ? obr(ft.get(i - 1)) : 1) % MOD;
      p.pop_back();
    }
    if (i + 1 == n)
      break;
    for (int x : imcap[i]) {
      if (cur[x] != i)
        continue;
      int id = upper_bound(vhozh[x].begin(), vhozh[x].end(), i) - vhozh[x].begin();
      if (id == vhozh[x].size())
        continue;
      imcap[vhozh[x][id]].push_back(x);
      cur[x] = vhozh[x][id];
      ft.upd(vhozh[x][id], (x - 1) * 1ll * rev[x] % MOD);
    }
  }
  for (auto &now : answer)
    cout << now << '\n';
  return 0;
}