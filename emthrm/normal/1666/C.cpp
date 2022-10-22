#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

constexpr int N = 3;

int main() {
  int x[N], y[N]; REP(i, N) cin >> x[i] >> y[i];
  {
    int ord[N]{};
    iota(ord, ord + N, 0);
    sort(ord, ord + N, [&](int a, int b) -> bool {
      return x[a] != x[b] ? x[a] < x[b] : y[a] < y[b];
    });
    int nx[N], ny[N];
    REP(i, N) {
      nx[i] = x[ord[i]];
      ny[i] = y[ord[i]];
    }
    swap(x, nx);
    swap(y, ny);
  }
  vector<tuple<int, int, int, int>> ans;
  if (*min_element(y, y + N) < *max_element(y, y + N)) {
    ans.emplace_back(x[N / 2], *min_element(y, y + N), x[N / 2], *max_element(y, y + N));
  }
  if (x[0] < x[N / 2]) ans.emplace_back(x[0], y[0], x[N / 2], y[0]);
  if (x[N - 1] > x[N / 2]) ans.emplace_back(x[N / 2], y[N - 1], x[N - 1], y[N - 1]);
  cout << ans.size() << '\n';
  for (const auto [x1, y1, x2, y2] : ans) cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
  return 0;
}