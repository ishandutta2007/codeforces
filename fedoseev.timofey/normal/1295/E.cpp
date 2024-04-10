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
#include <cassert>
#include <complex>
#include <functional>
 
using namespace std;
 
typedef long long ll;

const int N = 2e5 + 7;

ll t[4 * N];
ll mod[4 * N];

void update(int v, ll x) {
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

void modify(int ql, int qr, ll x, int l, int r, int v) {
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

ll get() {
  return t[0];
}

int n;

void addL(int pos, int cost) {
  if (pos > 0) {
    //cout << "+ " << 0 << ' ' << pos - 1 << ' ' << cost << endl;
    modify(0, pos - 1, cost, 0, n - 2, 0);
  }
} 

void delL(int pos, int cost) {
  if (pos > 0) {
    //cout << "- " << 0 << ' ' << pos - 1 << ' ' << cost << endl;
    modify(0, pos - 1, -cost, 0, n - 2, 0);
  }
}

void addR(int pos, int cost) {
  if (pos <= n - 2) {
    //cout << "+ " << pos << ' ' << n - 2 << ' ' << cost << endl;
    modify(pos, n - 2, cost, 0, n - 2, 0);
  }
} 

void delR(int pos, int cost) {
  if (pos <= n - 2) {
    modify(pos, n - 2, -cost, 0, n - 2, 0);
  }
} 


int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  cin >> n;
  vector <int> p(n);
  vector <int> pos(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
    pos[p[i]] = i;
  }
  vector <int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    addL(pos[i], a[pos[i]]);
  }
  ll ans = get();
  for (int x = n - 1; x >= 0; --x) {
    delL(pos[x], a[pos[x]]);
    addR(pos[x], a[pos[x]]);
    ans = min(ans, get());
  }
  cout << ans << '\n';
}