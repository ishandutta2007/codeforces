#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;

int main() {
  constexpr int N = 500000;
  int q; cin >> q;
  vector<int> m, ans;
  set<pair<int, int>> st;
  vector<bool> v(N, false);
  int id = 0, mono = 0;
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      m.emplace_back(); cin >> m.back();
      st.emplace(-m.back(), id++);
    } else if (type == 2) {
      while (v[mono]) ++mono;
      ans.emplace_back(mono);
      v[mono] = true;
      st.erase(make_pair(-m[mono], mono));
    } else if (type == 3) {
      int poly = st.begin()->second;
      ans.emplace_back(poly);
      v[poly] = true;
      st.erase(st.begin());
    }
  }
  REP(i, ans.size()) cout << ans[i] + 1 << " \n"[i + 1 == ans.size()];
  return 0;
}