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

int C(int n, int m) {
  if (2 * m > n)
    m = n - m;
  if (m == 0)
    return 1;
  if (m < 0)
    return 0;
  return C(n - 1, m) + C(n - 1, m - 1);
}

int main() {
  ioThings();

  cout << setprecision(9) << fixed;

  string a, b; cin >> a >> b;
  int init = count(all(a), '+') - count(all(a), '-') - count(all(b), '+') + count(all(b), '-');
  int guess = count(all(b), '?');
  if (guess == 0)
    cout << (init ? 0 : 1);
  else {
    int x = guess - init;
    if (x % 2)
      cout << 0;
    else
      cout << (double)C(guess, x / 2) / (1 << guess);
  }

  return 0;
}