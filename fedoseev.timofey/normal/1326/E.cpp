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

const int N = 3e5 + 7;

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
    t[v] = max(t[2 * v + 1], t[2 * v + 2]);
  }
}

int get() {
  return t[0];
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> p(n);
  vector <int> where(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
    where[p[i]] = i;
  }
  vector <int> q(n);
  for (int i = 0; i < n; ++i) {
    cin >> q[i];
    --q[i];
  }
  vector <int> ans(n);
  int uk = 0;
  for (int x = n - 1; x >= 0; --x) {
    modify(0, where[x], 1, 0, n - 1, 0);
    while (uk < n && get() > 0) {
      ans[uk] = x + 1;
      modify(0, q[uk], -1, 0, n - 1, 0);
      ++uk;
    }
  } 
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }
}