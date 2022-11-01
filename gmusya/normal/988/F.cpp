#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

const ll INF = 1e9;

struct convex_hull_trick {
  struct line {
    ll k, b;
    line(ll _k, ll _b) {
      k = _k, b = _b;
    }
  };
  int n;
  vector <line> lines;
  convex_hull_trick() {
    n = 1;
    line line_new(INF, 0);
    lines.push_back(line_new);
  }
  void add(ll k, ll b) {
    line line_new(k, b);
    lines.push_back(line_new);
    n = lines.size();
  }
  ll get(ll x) {
    ll ans = INF;
    for (int i = 0; i < n; i++)
      ans = min(ans, lines[i].b + lines[i].k * x);
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, n, m;
  cin >> a >> n >> m;
  vector <int> l(n), r(n);
  for (int i = 0; i < n; i++)
    cin >> l[i] >> r[i];
  vector <bool> wet(a + 1);
  for (int i = 0; i < n; i++)
    for (int j = l[i]; j < r[i]; j++)
      wet[j] = true;
  vector <int> x(m), w(m);
  for (int i = 0; i < m; i++)
    cin >> x[i] >> w[i];
  vector <int> p(m);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) {
    return x[i] < x[j];
  });
  vector <ll> ans(a + 1);
  int it = 0;
  convex_hull_trick cht;
  for (int cur_x = 0; cur_x < a; cur_x++) {
    while (it < m && x[p[it]] == cur_x) {
      ll k = w[p[it]];
      ll b = ans[cur_x] - k * cur_x;
      cht.add(k, b);
      it++;
    }
    ans[cur_x + 1] = (wet[cur_x] ? cht.get(cur_x + 1) : ans[cur_x]);
  }
  if (ans.back() >= INF)
    ans.back() = -1;
  cout << ans.back();
  return 0;
}