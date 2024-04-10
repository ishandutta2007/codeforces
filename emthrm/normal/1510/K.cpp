#include <bits/stdc++.h>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
  }
} iosetup;

int main() {
  int n; cin >> n;
  vector<int> p(n * 2); REP(i, n * 2) cin >> p[i];
  vector<int> q = p;
  int ans = n * 2;
  bool op1 = true;
  REP(op, n * 2) {
    if (is_sorted(ALL(p))) {
      ans = min(ans, op);
      break;
    }
    if (op1) {
      for (int i = 0; i < n * 2; i += 2) swap(p[i], p[i + 1]);
    } else {
      REP(i, n) swap(p[i], p[n + i]);
    }
    op1 = !op1;
  }
  op1 = false;
  REP(op, n * 2) {
    if (is_sorted(ALL(q))) {
      ans = min(ans, op);
      break;
    }
    if (op1) {
      for (int i = 0; i < n * 2; i += 2) swap(q[i], q[i + 1]);
    } else {
      REP(i, n) swap(q[i], q[n + i]);
    }
    op1 = !op1;
  }
  cout << (ans == n * 2 ? -1 : ans) << '\n';
  return 0;
}