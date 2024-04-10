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

const int N = 2e5 + 7;

long long t[4 * N], mod[4 * N];

void update(int v, int l, int r, long long x) {
  t[v] += x * (r - l + 1);
  mod[v] += x;
}

void push(int v, int l, int r) {
  if (mod[v]) {
    int m = (l + r) >> 1;
    update(2 * v + 1, l, m, mod[v]);
    update(2 * v + 2, m + 1, r, mod[v]);
    mod[v] = 0;
  }
}

void modify(int ql, int qr, long long x, int l, int r, int v) {
  if (qr < l || r < ql) return;
  if (ql <= l && r <= qr) {
    update(v, l, r, x);
  } else {
    push(v, l, r);
    int m = (l + r) >> 1;
    modify(ql, qr, x, l, m, 2 * v + 1);
    modify(ql, qr, x, m + 1, r, 2 * v + 2);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
  }
}

long long get(int ql, int qr, int l, int r, int v) {
  if (qr < l || r < ql) return 0;
  if (ql <= l && r <= qr) return t[v];
  push(v, l, r);
  int m = (l + r) >> 1;
  return get(ql, qr, l, m, 2 * v + 1) + get(ql, qr, m + 1, r, 2 * v + 2);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, q;
  cin >> n >> q;
  vector<int> p(n);
  vector<int> pos(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    pos[p[i]] = i;
  }
  vector<int> nxt(n, n), prv(n, -1);
  vector<int> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && p[st.back()] < p[i]) {
      st.pop_back();
    }
    if (!st.empty()) {
      prv[i] = st.back();
    }
    st.push_back(i);
  }
  st.clear();
  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && p[st.back()] < p[i]) {
      st.pop_back();
    }
    if (!st.empty()) {
      nxt[i] = st.back();
    }
    st.push_back(i);
  }
  vector<vector<int>> divs(n + 1);
  for (int x = 1; x <= n; ++x) {
    for (int y = x; y <= n; y += x) {
      divs[y].push_back(x);
    }
  }
  vector<vector<pair<int, int>>> by_l(n), by_r(n);
  for (int i = 0; i < n; ++i) {
    int left_min = prv[i] + 1;
    int right_max = nxt[i] - 1;
    vector<pair<int, int>> segs;
    for (int x : divs[p[i]]) {
      int y = p[i] / x;
      int l = min(pos[x], i);
      int r = max(pos[y], i);
      if (pos[x] < pos[y] && l <= r && left_min <= l && r <= right_max) {
        segs.emplace_back(l, r);
      }
    }
    sort(segs.begin(), segs.end(), [&](const pair<int, int> &p1, const pair<int, int> &p2) {
      if (p1.first != p2.first) {
        return p1.first < p2.first;
      } else {
        return p1.second > p2.second;
      }
    });
    int min_r = n; 
    vector<pair<int, int>> new_segs;
    for (int i = (int)segs.size() - 1; i >= 0; --i) {
      if (segs[i].second < min_r) {
        new_segs.push_back(segs[i]);
        min_r = segs[i].second;
      }
    }
    reverse(new_segs.begin(), new_segs.end());
    segs = new_segs;
    int last_l = left_min - 1;
    for (auto [l, r] : segs) {
      int l1 = last_l + 1;
      int l2 = l;
      int r1 = r;
      int r2 = right_max;
      last_l = l2;
      if (l2 - l1 < r2 - r1) {
        for (int l = l1; l <= l2; ++l) {
          by_l[l].emplace_back(r1, r2);
        }
      } else {
        for (int r = r1; r <= r2; ++r) {
          by_r[r].emplace_back(l1, l2);
        }
      } 
    }
  }
  vector<int> ql(q), qr(q);
  vector<vector<int>> who_l(n), who_r(n);
  vector<long long> ans(q);
  for (int tt = 0; tt < q; ++tt) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    ql[tt] = l, qr[tt] = r;
    who_l[l].push_back(tt);
    who_r[r].push_back(tt);
  }
  for (int i = 0; i < n; ++i) {
    for (auto id : who_l[i]) {
      ans[id] -= get(ql[id], qr[id], 0, n - 1, 0);
    }
    for (auto [r1, r2] : by_l[i]) {
      modify(r1, r2, 1, 0, n - 1, 0);
    }
    for (auto id : who_r[i]) {
      ans[id] += get(ql[id], qr[id], 0, n - 1, 0);
    }
  }
  memset(t, 0, sizeof(t));
  memset(mod, 0, sizeof(mod));
  for (int i = n - 1; i >= 0; --i) {
    for (auto id : who_r[i]) {
      ans[id] -= get(ql[id], qr[id], 0, n - 1, 0);
    }
    for (auto [l1, l2] : by_r[i]) {
      modify(l1, l2, 1, 0, n - 1, 0);
    }
    for (auto id : who_l[i]) {
      ans[id] += get(ql[id], qr[id], 0, n - 1, 0);
    }
  }
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << '\n';
  }
}