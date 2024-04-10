#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll



bool ok(vector<int> v) {
  int n = (int) v.size();
  for (int i = 0; i + 1 < n; i++) {
    if (!(v[i + 1] >= v[i] - 1)) {
      return 0;
    }
  }
  return 1;
}

void printv(vector<int> v) {
  cout << " ---> ";
  for (auto &x : v) {
    cout << x << " ";
  }
  cout << "\n";
}

int cnt;

void prn(vector<int> v) {
  if (ok(v)) {
    cnt++;
    cout << cnt;
    printv(v);
  }
}

void rec(int n) {
  cnt = 0;
  vector<int> v(n);
  iota(v.begin(), v.end(), 1);
  prn(v);
  while (next_permutation(v.begin(), v.end())) {
    prn(v);
  }
}

int pw2(int n) {
  n = min(n, 60LL);
  return (1LL << n);
}

void rec(int n, int k, int push) {
  if (k == 1) {
    for (int i = 1; i <= n; i++) {
      cout << i + push << " ";
    }
    cout << "\n";
    return;
  }
  assert(n > 1);
  assert(k <= pw2(n - 1));
  for (int x = 1; x <= n; x++) {
    if (x == n || k <= pw2(n - x - 1)) {
      for (int i = x; i >= 1; i--) {
        cout << i + push << " ";
      }
      rec(n - x, k, push + x);
      return;
    } else {
      k -= pw2(n - x - 1);
    }
  }
}

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, val = 1;
    cin >> n >> k;
    if (k > pw2(n - 1)) {
      cout << "-1\n";
      continue;
    }
    rec(n, k, 0);
    ///cout << "???\n";
  }
  exit(0);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ///freopen ("input", "r", stdin);
  solve();
  for (int i = 1; i <= 100; i++) {
    i = 5;
    rec(i);
    cout << "\n";
    return 0;
  }
  return 0;
}