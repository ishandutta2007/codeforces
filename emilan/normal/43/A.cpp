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

int main() {
  ioThings();

  int n; cin >> n;
  map<string, int> ma;
  while (n--) {
    string m; cin >> m;
    ma[m]++;
  }

  cout << (ma.rbegin()->se > ma.begin()->se ? ma.rbegin()->fi : ma.begin()->fi);

  return 0;
}