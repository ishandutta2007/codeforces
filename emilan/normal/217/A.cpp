#include <bits/stdc++.h>
using namespace std;

// #define int ll
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n) for (int i = 0; i < n; i++)
#define dotc()    int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)     (int)x.size()
#define eb        emplace_back
#define pb        push_back
#define mp        make_pair
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second

ll mod(1000000007);
double pi(acos(-1.0));

vector<vii> row(1000), col(1000);

void sweepCol(int x, int v);

void sweepRow(int x, int v) {
  for (auto& i : row[x]) {
    if (i.se != v) {
      i.se = v;
      sweepCol(i.fi, v);
    }
  }
}

void sweepCol(int y, int v) {
  for (auto& i : col[y]) {
    if (i.se != v) {
      i.se = v;
      sweepRow(i.fi, v);
    }
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif

  int n;
  cin >> n;

  rep(i, n) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    row[x].pb({y, i});
    col[y].pb({x, i});
    sweepRow(x, i);
    sweepCol(y, i);
  }


  si groups;
  rep(i, 1000) {
    for (auto z : row[i]) groups.insert(z.se);
    for (auto z : col[i]) groups.insert(z.se);
  }

  cout << sz(groups) - 1;

  return 0;
}