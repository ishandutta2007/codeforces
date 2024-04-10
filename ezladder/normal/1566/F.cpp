#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

int n, m;
ll a[200007];
pair<ll, ll> b[200007];

vector<pair<ll, ll>> dp[200007];

void solve() {
  cin >> n >> m;
  readArr(a, a + n);
  readArr(b, b + m);

  sort(a, a + n);

  for (int i = 0; i < n; ++i) dp[i].clear();

  vector<pair<ll, ll> > t;

  for (int i = 0; i < m; ++i) {
    int vl = -1, vr = n;
    while (vl + 1 < vr) {
      int vm = (vl + vr) >> 1;
      if (a[vm] < b[i].x) vl = vm; else vr = vm;
    }
    if (vr == n || a[vr] > b[i].y) t.pb(b[i]);
  }

  sort(all(t));

  for (int i = 0; i < n; ++i) {

    ll last = -1e9 - 7;
    if (i) last = a[i - 1];
    int vl = -1, vr = t.size();
    while (vl + 1 < vr) {
      int vm = (vl + vr) >> 1;
      if (t[vm].x > last) vr = vm; else vl = vm;
    }

    vector<pair<ll, ll> > d;
    for (int j = vr; j < t.size(); ++j) {
      if (t[j].x < a[i]) d.pb(t[j]); else break;
    }

    if (i) {

      ll val = 1e18;
      for (auto [w1, w2] : dp[i - 1]) uin(val, w2);

      if (d.size() == 0) {
        dp[i].pb(mp(0, val));
        continue;
      }

      sort(all(d));

      multiset<ll> se;
      for (auto [w1, w2] : d) se.insert(w2);


      ll ma = 1e9 + 7;
      for (auto [w1, w2] : d) uin(ma, w2);
      ma = a[i] - ma;

      dp[i].pb(mp(ma, ma + val));

      multiset<ll> MI;
      for (auto [w1, w2] : dp[i - 1]) MI.insert(w2);
      int uk = 0;
      ll CURR = 1e18;

      for (auto [w1, w2] : d) {
        se.erase(se.find(w2));

        ll cur_dist = w1 - a[i - 1];

        while (uk < dp[i - 1].size() && dp[i - 1][uk].x <= cur_dist) {
          uin(CURR, dp[i - 1][uk].y + dp[i - 1][uk].x);
          MI.erase(MI.find(dp[i - 1][uk++].y));
        }

        ll now = 1e18;
        if (MI.size() > 0) uin(now, (*MI.begin()) + cur_dist * 2);
        if (uk > 0) uin(now, CURR + cur_dist);


        if (se.size()) {
          ll dist = a[i] - (*se.begin());
          dp[i].pb(mp(dist, dist + now));
        } else {
          dp[i].pb(mp(0, now));
        }

      }

      sort(all(dp[i]));


    } else {

      if (d.size() == 0) {
        dp[0].pb(mp(0, 0));
      } else {
        ll ma = 1e9 + 7;
        for (auto [w1, w2] : d) uin(ma, w2);
        dp[0].pb(mp(a[0] - ma, a[0] - ma));
      }

    }

  }

  ll res = 1e18;

  vector<pair<ll, ll> > d;
  for (auto [w1, w2] : t) if (w1 > a[n - 1]) d.pb(mp(w1, w2));

  if (d.size()) {
    sort(all(d));

    ll dist = d.back().x - a[n - 1];

    for (auto [w1, w2] : dp[n - 1]) uin(res, w2 + dist + min(dist, w1));

  } else {
    for (auto [w1, w2] : dp[n - 1]) uin(res, w2);
  }

  cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }

}