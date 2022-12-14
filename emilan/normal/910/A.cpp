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

  int n, d;
  cin >> n >> d;
  string s;
  cin >> s;

  int p = 0, j = 0;
  for (int i = d; i > 0; i--) {
    if (p + i >= n) continue;
    if (s[p + i] == '1') {
      p += i;
      i = d + 1;
      j++;
      
      continue;
    }
  }

  if (p == n - 1) cout << j;
  else cout << -1;

  return 0;
}