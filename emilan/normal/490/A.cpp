#include <bits/stdc++.h>
using namespace std;

void ioThings() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
  freopen("io\\err.txt", "w", stderr);
#endif
}

using   ll        = long long;
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

int main() {
  ioThings();

  int n; cin >> n;
  vector<int> t[3];
  for (int i = 1; i <= n; i++) {
    int m; cin >> m;
    t[m - 1].pb(i);
  }
  int size = min({sz(t[0]), sz(t[1]), sz(t[2])});
  cout << size << '\n';
  for (int i = 0; i < size; i++) {
    cout << t[0][i] << ' ' << t[1][i] << ' ' << t[2][i] << '\n';
  }


  return 0;
}