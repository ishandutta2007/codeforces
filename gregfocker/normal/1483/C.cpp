#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = (int) 3e5 + 7;
const int INF = (int) 1e18;
int n, h[N], b[N], dp[N], rec[N];


int am[4 * N];
int sm[4 * N];
int lazy[4 * N];

void push(int v, int tl, int tr) {
  if (lazy[v] != -INF) {
    sm[v] = am[v] + lazy[v];
    if (tl < tr) {
      lazy[2 * v] = lazy[v];
      lazy[2 * v + 1] = lazy[v];
    }
    lazy[v] = -INF;
  }
}

void join(int v) {
  am[v] = max(am[2 * v], am[2 * v + 1]);
  sm[v] = max(sm[2 * v], sm[2 * v + 1]);
}

void upda(int v, int tl, int tr, int i, int val) {
  push(v, tl, tr);
  if (tr < i || i < tl) {
    return;
  }
  if (tl == tr) {
    sm[v] -= am[v];
    am[v] = val;
    sm[v] += am[v];
    return;
  }
  int tm = (tl + tr) / 2;
  upda(2 * v, tl, tm, i, val);
  upda(2 * v + 1, tm + 1, tr, i, val);
  join(v);
}

void updb(int v, int tl, int tr, int l, int r, int val) {
  push(v, tl, tr);
  if (tr < l || r < tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    lazy[v] = val;
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  updb(2 * v, tl, tm, l, r, val);
  updb(2 * v + 1, tm + 1, tr, l, r, val);
  join(v);
}

int get(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) {
    return -INF;
  }
  if (l <= tl && tr <= r) {
    return sm[v];
  }
  int tm = (tl + tr) / 2;
  return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

vector<int> stk;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  for (int i = 0; i < 4 * N; i++) lazy[i] = -INF;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    dp[i] = -INF;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    while (!stk.empty() && h[stk.back()] > h[i]) stk.pop_back();
    int j = (stk.empty()) ? 1 : (stk.back() + 1);
    stk.push_back(i);
    upda(1, 1, n, i, dp[i - 1]);
    updb(1, 1, n, j, i, b[i]);
    dp[i] = get(1, 1, n, 1, i);
  }
  cout << dp[n] << "\n";
}