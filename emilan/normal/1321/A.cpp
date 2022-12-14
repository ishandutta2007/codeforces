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

#define dotc()  int tcs; if (cin >> tcs) for (int tc = 0; tc < tcs; tc++)
#define sz(x)   (int)x.size()
#define eb      emplace_back
#define pb      push_back
#define all(x)  x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi      first
#define se      second
#define mod     1000000007

using ll = long long;
using vi = vector<int>;

int main() {
  ioThings();

  int n; cin >> n;
  vector<int> r(n), b(n);
  for (int i = 0; i < n; i++)
    cin >> r[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  int rw = 0, bw = 0;
  for (int i = 0; i < n; i++) {
    if (r[i] != b[i])
      rw += r[i], bw += b[i];
  }

  if (rw == 0)
    cout << "-1\n";
  else
    cout << max(1, bw / rw + 1);

  return 0;
}