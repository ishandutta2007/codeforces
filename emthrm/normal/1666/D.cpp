#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

constexpr int C = 26;

void solve() {
  string s, t; cin >> s >> t;
  bool can_use[C]{};
  fill(can_use, can_use + C, true);
  reverse(ALL(s));
  for (char c : s) {
    if (t.empty() || t.back() != c) {
      can_use[c - 'A'] = false;
    } else {
      if (!can_use[t.back() - 'A']) {
        cout << "NO\n";
        return;
      }
      t.pop_back();
    }
  }
  cout << (t.empty() ? "YES\n" : "NO\n");
}

int main() {
  int n; cin >> n;
  while (n--) solve();
  return 0;
}