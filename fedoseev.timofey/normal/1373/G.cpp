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

const int N = 4e5 + 7;
const int Inf = 2e9;

int t[4 * N];
int mod[4 * N];

void update(int v, int x) {
  t[v] += x;
  mod[v] += x;
}

void push(int v) {
  if (mod[v]) {
    update(2 * v + 1, mod[v]);
    update(2 * v + 2, mod[v]);
    mod[v] = 0;
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
    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
  }
}

int get(int ql, int qr, int l, int r, int v) {
  if (qr < l || r < ql) return Inf;
  if (ql <= l && r <= qr) return t[v];
  push(v);
  int m = (l + r) >> 1;
  return min(get(ql, qr, l, m, 2 * v + 1), get(ql, qr, m + 1, r, 2 * v + 2));
}

void build(int l, int r, int v, vector <int> &a) {
  if (l == r) {
    t[v] = a[l];
    mod[v] = 0;
  } else {
    int m = (l + r) >> 1;
    build(l, m, 2 * v + 1, a);
    build(m + 1, r, 2 * v + 2, a);
    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
    mod[v] = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, k, m;
  cin >> n >> k >> m;
  {
    vector <int> have(N);
    for (int i = 0; i < N; ++i) {
      have[i] = N - i;
    }
    build(0, N - 1, 0, have);
  }
  set <pair <int, int>> have;
  multiset <int> gs;
  for (int i = 0; i < m; ++i) {
    int y, x;
    cin >> y >> x;
    --x;
    int go = x + abs(k - y);
    if (have.count({x, y})) {
      have.erase({x, y}); 
      gs.erase(gs.find(go));
      modify(0, go, 1, 0, N - 1, 0);
    } else {
      have.insert({x, y});
      gs.insert(go);
      modify(0, go, -1, 0, N - 1, 0);
    }
    if (gs.empty()) {
      cout << "0\n";
    } else {
      int mx = *gs.rbegin();
      int need = get(0, mx, 0, N - 1, 0);
      need -= N - n;
      cout << max(0, -need) << '\n';
    }
  } 
}