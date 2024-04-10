#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

struct segment_tree {
  int n;
  vector <ll> t;
  vector <ll> mod;
  segment_tree(int _n) {
    n = _n;
    t.resize(n << 2);
    mod.resize(n << 2);
  }
  void build(int v, int tl, int tr, vector <ll> &a) {
    if (tl == tr) {
      t[v] = a[tl];
      mod[v] = 0;
      return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
    mod[v] = 0;
  }
  void set(int v, int tl, int tr, int l, int r, ll val) {
    t[v] = max(t[v], mod[v]);
    if (l > r)
      return;
    if (l == tl && r == tr) {
      mod[v] = max(mod[v], val);
      t[v] = max(t[v], mod[v]);
      return;
    }
    mod[v * 2] = max(mod[v * 2], mod[v]);
    mod[v * 2 + 1] = max(mod[v * 2 + 1], mod[v]);
    mod[v] = 0;
    int tm = (tl + tr) / 2;
    set(v * 2, tl, tm, l, min(r, tm), val);
    set(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
  }
  pair <int, ll> get(int v, int tl, int tr) {
    if (tl == tr)
      return {tl, t[v]};
    mod[v * 2] = max(mod[v * 2], mod[v]);
    mod[v * 2 + 1] = max(mod[v * 2 + 1], mod[v]);
    t[v * 2] = max(t[v * 2], mod[v * 2]);
    t[v * 2 + 1] = max(t[v * 2 + 1], mod[v * 2 + 1]);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
    int tm = (tl + tr) / 2;
    if (t[v * 2] <= t[v * 2 + 1])
      return get(v * 2, tl, tm);
    else
      return get(v * 2 + 1, tm + 1, tr);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  ll c;
  cin >> n;
  cin >> c;
  vector <ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  ll time = 0;
  segment_tree se(n);
  vector <ll> answer(n);
  se.build(1, 0, n - 1, a);
  for (int i = 0; i < n; i++) {
    pair <int, ll> ans = se.get(1, 0, n - 1);
    answer[ans.first] = max(time, ans.second) + c;
    time = answer[ans.first];
    se.set(1, 0, n - 1, ans.first, n - 1, time);
    se.set(1, 0, n - 1, ans.first, ans.first, INF);
  }
  for (auto &now : answer)
    cout << now << ' ';
  return 0;
}