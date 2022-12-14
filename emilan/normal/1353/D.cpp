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

struct seg {
  int l, r;
  bool operator<(const seg& o) const {
    if (r - l < o.r - o.l) return true;
    else if (r - l == o.r - o.l) return l > o.l;
    return false;
  }
};

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif

  dotc() {
    int n;
    cin >> n;
    vi a(n);
    priority_queue<seg> q;
    q.push({0, sz(a) - 1});
    int i = 0;
    while (!q.empty()) {
      seg cur = q.top();
      q.pop();
      if (cur.l > cur.r) continue;
      int mi = (cur.l + cur.r) / 2;
      a[mi] = ++i;
      q.push({cur.l, mi - 1});
      q.push({mi + 1, cur.r});
    }
    for (int i : a) cout << i << ' ';
    cout << '\n';
  }

  return 0;
}