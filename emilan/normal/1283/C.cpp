#include <bits/stdc++.h>
using namespace std;

inline void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#define debug(x) cerr << #x << ": <" << (x) << ">\n"
#else
#define debug(x)
#endif
}

#define rep(i, n) for (int i = 0; i < n; i++)
#define dotc()    int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)     (int)x.size()
#define eb        emplace_back
#define pb        push_back
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second
#define mod       1000000007

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  int n; cin >> n;
  vector<int> a(n);
  set<int> s;
  rep(i, n) s.insert(i + 1);
  rep(i, n) {
    cin >> a[i];
    s.erase(a[i]);
  }

  vector<int> v;
  rep(i, n) if (!a[i]) v.pb(i);

  for (int i = 0; i < sz(v); i++) {
    auto p = s.begin();
    if (v[i] + 1 == *p) {
      if (sz(s) != 1) p++;
      else {
        a[v[i]] = a[v[0]];
        v[i] = v[0];
      }
    } 
    a[v[i]] = *p;
    s.erase(p);
  }

  for (auto& i : a) cout << i << ' ';

  return 0;
}