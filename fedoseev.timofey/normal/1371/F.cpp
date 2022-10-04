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
 
using namespace std;
 
typedef long long ll;
 
struct Node {
  int best[2][2], pref[2][2], suf[2][2], all[2][2];
  int sz;
  Node(int x) {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        best[i][j] = pref[i][j] = suf[i][j] = all[i][j] = 0;
      }
    }
    best[0][x] = best[1][x] = best[x][0] = best[x][1] = 1;
    pref[0][x] = pref[1][x] = pref[x][0] = pref[x][1] = 1;
    suf[0][x] = suf[1][x] = suf[x][0] = suf[x][1] = 1;
    all[0][x] = all[1][x] = all[x][0] = all[x][1] = 1;
    sz = 1;
  }
  Node() {
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        best[i][j] = pref[i][j] = suf[i][j] = all[i][j] = 0;
      }
    }
    sz = 0;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        all[i][j] = 1;
      }
    }
  }
  Node rev() const {
    Node res;
    res.sz = sz;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        res.best[i][j] = best[i ^ 1][j ^ 1];
      }
    }
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        res.pref[i][j] = pref[i ^ 1][j ^ 1];
      }
    }
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        res.suf[i][j] = suf[i ^ 1][j ^ 1];
      }
    }
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        res.all[i][j] = all[i ^ 1][j ^ 1];
      }
    }
    return res;
  }
  Node operator +(const Node &other) const {
    Node res;
    res.sz = sz + other.sz;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        res.best[i][j] = max(best[i][j], other.best[i][j]);
      }
    }
 
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        res.best[i][j] = max(res.best[i][j], suf[i][i] + other.pref[i][j]);
        res.best[i][j] = max(res.best[i][j], suf[i][j] + other.pref[j][j]);
      }
    }
 
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        res.pref[i][j] = pref[i][j] + (all[i][j] ? other.pref[j][j] : 0);
        if (all[i][i]) {
          res.pref[i][j] = max(res.pref[i][j], pref[i][i] + other.pref[i][j]);
        }
      }
    }
 
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        res.suf[i][j] = other.suf[i][j] + (other.all[i][j] ? suf[i][i] : 0);
        if (other.all[j][j]) {
          res.suf[i][j] = max(res.suf[i][j], other.suf[j][j] + suf[i][j]);
        }
      }
    }
 
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        if (res.best[i][j] == res.sz) {
          res.all[i][j] = 1;
        } else {
          res.all[i][j] = 0;
        }
      }
    }
    return res;
  } 
};
 
const int N = 5e5 + 7;
 
Node t[4 * N];
int mod[4 * N];
 
void build(int l, int r, int v, vector <int> &a) {
  if (l == r) {
    t[v] = Node(a[l]);
  } else {
    int m = (l + r) >> 1;
    build(l, m, 2 * v + 1, a);
    build(m + 1, r, 2 * v + 2, a);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
  }
}
 
void update(int v) {
  t[v] = t[v].rev();
  mod[v] ^= 1;
}
 
void push(int v) {
  if (mod[v]) {
    update(2 * v + 1);
    update(2 * v + 2);
    mod[v] = 0;
  }
}   
 
void modify(int ql, int qr, int l, int r, int v) {
  if (qr < l || r < ql) return;
  if (ql <= l && r <= qr) {
    update(v);
  } else {
    push(v);
    int m = (l + r) >> 1;
    modify(ql, qr, l, m, 2 * v + 1);
    modify(ql, qr, m + 1, r, 2 * v + 2);
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
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  {
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
      if (s[i] == '>') a[i] = 0;
      else a[i] = 1;
    }
    build(0, n - 1, 0, a);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    modify(l, r, 0, n - 1, 0);
    auto res = get(l, r, 0, n - 1, 0);
    cout << res.best[0][1] << '\n';
  }
}