#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

typedef long long ll;

const ll INF = 1e9;

struct segment_tree {
  ll maxpos = INF;
  int tail = 1;
  vector <int> left, right;
  vector <ll> t, mod;
  void pball() {
    left.push_back(-1);
    right.push_back(-1);
    t.push_back(INF);
    mod.push_back(INF);
  }
  segment_tree() {
    pball();
  }
  void push(int v) {
    if (left[v] == -1) {
      left[v] = tail++;
      pball();
      right[v] = tail++;
      pball();
    }
    t[left[v]] = min(t[left[v]], mod[v]);
    t[right[v]] = min(t[right[v]], mod[v]);
    mod[left[v]] = min(mod[left[v]], mod[v]);
    mod[right[v]] = min(mod[right[v]], mod[v]);
  }
  ll get(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return INF;
    if (l == tl && r == tr)
      return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    ll x = get(left[v], tl, tm, l, min(r, tm));
    ll y = get(right[v], tm + 1, tr, max(l, tm + 1), r);
    t[v] = min(t[left[v]], t[right[v]]);
    return min(x, y);
  }
  void upd(int v, int tl, int tr, int l, int r, ll val) {
    if (l > r)
      return;
    if (l == tl && r == tr) {
      t[v] = min(val, t[v]);
      mod[v] = min(val, mod[v]);
      return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    upd(left[v], tl, tm, l, min(r, tm), val);
    upd(right[v], tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = min(t[left[v]], t[right[v]]);
  }
  ll get(int l, int r) {
    return get(0, 0, maxpos, l, r);
  }
  void upd(ll l, ll r, ll val) {
    l = max(0ll, l);
    r = min(maxpos, r);
    upd(0, 0, maxpos, l, r, val);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <ll> x(n), t(n);
  for (int i = 0; i < n; i++)
    cin >> x[i] >> t[i];
  vector <ll> p(m), b(m);
  for (int i = 0; i < m; i++)
    cin >> p[i] >> b[i];
  segment_tree st;
  vector <int> per(n);
  iota(per.begin(), per.end(), 0);
  sort(per.begin(), per.end(), [&](int i, int j) {
    return x[i] < x[j];
  });
  vector <int> c(n);
  for (int i = 0; i < n; i++)
    st.upd(x[per[i]], x[per[i]] + t[per[i]], i);
  set <pair <ll, int>> yama;
  for (int i = 0; i < m; i++) {
    int id = st.get(p[i], p[i]);
    if (id == INF) {
      yama.insert({p[i], i});
      continue;
    }
    c[per[id]]++;
    t[per[id]] += b[i];
    auto left = yama.lower_bound({x[per[id]], -1});
    vector <pair <ll, int>> toerase;
    while (left != yama.end()) {
      if (x[per[id]] + t[per[id]] < left->first)
        break;
      c[per[id]]++;
      t[per[id]] += b[left->second];
      toerase.push_back(*left);
      left++;
    }
    for (auto &now : toerase)
      yama.erase(now);
    st.upd(x[per[id]], x[per[id]] + t[per[id]], id);
  }
  for (int i = 0; i < n; i++)
    cout << c[i] << ' ' << t[i] << '\n';
  return 0;
}