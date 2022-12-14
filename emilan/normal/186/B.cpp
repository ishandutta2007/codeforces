#include <bits/stdc++.h>
using namespace std;

inline void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif
}

#define debug(x)    cerr << #x << ": <" << (x) << ">\n"
#define dotc()      int tcs; if (cin >> tcs) for (int tc = 0; tc < tcs; tc++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second
#define mod         1000000007

using ll = long long;
using vi = vector<int>;

struct Parti {
  double height;
  int id;
  bool operator<(Parti& other) {
    if (abs(height - other.height) < 1e-3)
      return id < other.id;
    return height > other.height;
  }
};

int main() {
  ioThings();

  int n, t1, t2, k; cin >> n >> t1 >> t2 >> k;
  vector<Parti> p(n);
  for (int i = 0; i < n; i++) {
    int v1, v2; cin >> v1 >> v2;
    p[i].height = max(v1 * t1 * (100 - k) / 100.0 + v2 * t2, v1 * t2 + v2 * t1 * (100 - k) / 100.0);
    p[i].id = i + 1;
  }

  sort(all(p));

  cout << setprecision(2) << fixed;

  for (auto& i : p) {
    cout << i.id << ' ' << i.height << '\n';
  }

  return 0;
}