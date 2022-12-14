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

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif

  int n, m;
  cin >> n >> m;

  vvi adjDir(n + 1), adjRev(n + 1);
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    adjDir[x].pb(y);
    adjRev[y].pb(x);
  }

  int k;
  cin >> k;
  vi p(k);
  rep(i, k) cin >> p[i];

  vi dist(n + 1, -1);
  dist[p[k - 1]] = 0;
  queue<int> q;
  q.push(p[k - 1]);
  while (!q.empty()) {
    int node = q.front();
    q.pop();

    int step = dist[node] + 1;
    for (int i : adjRev[node]) {
      if (dist[i] != -1) continue;
      dist[i] = step;
      q.push(i);
    }
  }

  int mn = 0, mx = 0;
  rep(r, k - 1) {
    int shortest = 1 << 30, shortCnt = 0;
    for (int i : adjDir[p[r]]) {
      if (dist[i] < shortest) shortCnt = 1, shortest = dist[i];
      else if (dist[i] == shortest) shortCnt++;
    }

    if (shortest != dist[p[r + 1]]) mn++, mx++;
    else {
      if (shortCnt != 1) mx++;
    }
  }

  cout << mn << ' ' << mx;

  return 0;
}