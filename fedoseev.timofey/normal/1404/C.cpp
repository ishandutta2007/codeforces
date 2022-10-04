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
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
 
const int N = 3e5 + 7;
const int Inf = 1e9;

struct Node {
  int mn, id;
  Node(int x, int i) {
    mn = x;
    id = i;
  }
  Node() {
    mn = Inf;
    id = -1;
  }
  Node operator +(const Node &other) const {
    Node res;
    res.mn = min(mn, other.mn);
    res.id = -1;
    if (res.mn == mn) res.id = max(res.id, id);
    if (res.mn == other.mn) res.id = max(res.id, other.id);
    return res;
  }
};

Node t[4 * N];
int mod[4 * N];

void update(int v, int x) {
  t[v].mn += x;
  mod[v] += x;
}

void push(int v) {
  if (mod[v]) {
    update(2 * v + 1, mod[v]);
    update(2 * v + 2, mod[v]);
    mod[v] = 0;
  }
}

void build(int l, int r, int v, vector <int> &a) {
  if (l == r) {
    t[v] = Node(a[l], l);
  } else {
    int m = (l + r) >> 1;
    build(l, m, 2 * v + 1, a);
    build(m + 1, r, 2 * v + 2, a);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
  }
}

void modify(int ql, int qr, int x, int l, int r, int v) {
  if (qr < l || r < ql) return;
  if (ql <= l && r <= qr) {
    update(v, x);
  } else {
    push(v);
    int m = (l + r) >> 1;
    modify(ql, qr, x, l, m, 2 * v + 1);
    modify(ql, qr, x, m + 1, r, 2 * v + 2);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
  } 
}

Node get(int ql, int qr, int l, int r, int v) {
  if (qr < l || r < ql) return Node();
  if (ql <= l && r <= qr) return t[v];
  push(v);
  int m = (l + r) >> 1;
  return get(ql, qr, l, m, 2 * v + 1) + get(ql, qr, m + 1, r, 2 * v + 2);
} 

void kill(int id, int l, int r, int v) {
  if (l == r) {
    t[v] = Node();
  } else {
    push(v); 
    int m = (l + r) >> 1;
    if (id <= m) kill(id, l, m, 2 * v + 1);
    else kill(id, m + 1, r, 2 * v + 2);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
  }
} 

struct Query {
  int x, y, id;
  bool operator <(const Query &other) const {
    return x < other.x;
  }
};

int f[N];

void modify(int i) {
  for (; i < N; i |= i + 1) {
    ++f[i];
  }
}

int get(int r) {
  int res = 0;
  for (; r >= 0; r &= r + 1, --r) {
    res += f[r];
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, q;
  cin >> n >> q;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    a[i] = (i + 1) - a[i];
    if (a[i] < 0) {
      a[i] = Inf;
    }   
  } 
  build(0, n - 1, 0, a);
  vector <Query> qr;
  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    qr.push_back({x, y, i});
  }
  sort(qr.begin(), qr.end());
  vector <int> ans(q);
  while (true) {
    auto cur = t[0];
    //cout << cur.mn << ' ' << cur.id << endl;
    if (cur.mn == 0) {
      int go = cur.id;
      while (!qr.empty() && qr.back().x > go) { 
        ans[qr.back().id] = get(n - qr.back().y - 1); 
        qr.pop_back();
      }
      modify(cur.id);
      kill(cur.id, 0, n - 1, 0);
      modify(cur.id, n - 1, -1, 0, n - 1, 0);
    } else {
      break;
    }
  }
  for (auto qq : qr) {
    ans[qq.id] = get(n - qq.y - 1);
  }
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << '\n';
  } 
}