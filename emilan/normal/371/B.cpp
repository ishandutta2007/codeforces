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

  int a, b; cin >> a >> b;
  int g = __gcd(a, b);
  a /= g, b /= g;

  int ops = 0;
  for (int i = 2; i < 6; i++) {
    while (a % i == 0)
      a /= i, ops++;
  }

  for (int i = 2; i < 6; i++) {
    while (b % i == 0)
      b /= i, ops++;
  }

  cout << (a == b ? ops : -1);

  return 0;
}