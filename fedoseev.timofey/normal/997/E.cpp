#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

struct Node {
  int mn, cnt, mod, min_mod;
  ll answer;
  Node(int val) {
    mn = val;
    cnt = 1;
    mod = min_mod = answer = 0;
  }
  Node() {
    mn = cnt = mod = min_mod = answer = 0;
  }
  Node operator +(const Node &other) const {
    Node res;
    res.mn = min(mn, other.mn);
    if (res.mn == mn) res.cnt += cnt;
    if (res.mn == other.mn) res.cnt += other.cnt;
    res.answer = answer + other.answer;
    return res;
  }
};

const int N = 15e4 + 7;

Node t[4 * N];

void add_val(int v, int x) {
  t[v].mn += x;
  t[v].mod += x;
}

void add_min(int v, int x) {
  t[v].answer += (ll)x * t[v].cnt;
  t[v].min_mod += x;
}

void push(int v) {
  if (t[v].mod) {
    add_val(2 * v + 1, t[v].mod);
    add_val(2 * v + 2, t[v].mod);
    t[v].mod = 0;
  }
  if (t[v].min_mod) {
    if (t[v].mn == t[2 * v + 1].mn) {
      add_min(2 * v + 1, t[v].min_mod);
    }
    if (t[v].mn == t[2 * v + 2].mn) {
      add_min(2 * v + 2, t[v].min_mod);
    }
    t[v].min_mod = 0;
  }
}

void modify_val(int ql, int qr, int x, int l, int r, int v) {
  if (qr < l ||r < ql) return;
  if (ql <= l && r <= qr) {
    add_val(v, x);
  } else {
    push(v);
    int m = (l + r) >> 1;
    modify_val(ql, qr, x, l, m, 2 * v + 1);
    modify_val(ql, qr, x, m + 1, r, 2 * v + 2);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
  }
}

void modify_min(int ql, int qr, int x, int l, int r, int v) {
  if (qr < l || r < ql) return;
  if (ql <= l && r <= qr) {
    add_min(v, x);
  } else {
    push(v);
    int m = (l + r) >> 1;
    modify_min(ql, qr, x, l, m, 2 * v + 1);
    modify_min(ql, qr, x, m + 1, r, 2 * v + 2);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
  }
}

ll get(int ql, int qr, int l, int r, int v) {
  if (qr < l || r < ql) return 0;
  if (ql <= l && r <= qr) return t[v].answer;
  push(v);
  int m = (l + r) >> 1;
  return get(ql, qr, l, m, 2 * v + 1) + get(ql, qr, m + 1, r, 2 * v + 2);
} 

int get_val(int id, int l, int r, int v) {
  if (l == r) return t[v].mn;
  push(v);
  int m = (l + r) >> 1;
  if (id <= m) return get_val(id, l, m, 2 * v + 1);
  else return get_val(id, m + 1, r, 2 * v + 2);
}

void build(int l, int r, int v) {
  if (l == r) {
    t[v] = Node(l); 
  } else {
    int m = (l + r) >> 1;
    build(l, m, 2 * v + 1);
    build(m + 1, r, 2 * v + 2);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
  int q;
  cin >> q;
  vector <vector <pair <int, int>>> who(n);
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    who[r].emplace_back(l, i);
  }
  vector <ll> ans(q);
  build(0, n - 1, 0);
  vector <int> mx, mn;  
  for (int i = 0; i < n; ++i) {
    modify_val(0, n - 1, -1, 0, n - 1, 0);
    while (!mx.empty() && a[i] > a[mx.back()]) {
      int id = (mx.size() == 1 ? 0 : mx.rbegin()[1] + 1);
      modify_val(id, mx.back(), a[i] - a[mx.back()], 0, n - 1, 0);
      mx.pop_back();
    }
    mx.push_back(i);
    while (!mn.empty() && a[i] < a[mn.back()]) {
      int id = (mn.size() == 1 ? 0 : mn.rbegin()[1] + 1);
      modify_val(id, mn.back(), a[mn.back()] - a[i], 0, n - 1, 0);
      mn.pop_back();
    }
    mn.push_back(i);
    modify_min(0, n - 1, 1, 0, n - 1, 0);
    for (auto p : who[i]) {
      ans[p.second] = get(p.first, i, 0, n - 1, 0);
    }
  }
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << '\n';
  }
}