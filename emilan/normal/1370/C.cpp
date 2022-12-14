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

int inf(0x3fffffff);
int mod(1000000007);
double pi(acos(-1.0));

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

    if ((n != 1 && n & 1) || n == 2) {
      cout << "Ashishgup\n";
      continue;
    }

    int odd = 0, two = 0;
    for (int i = 2; i * i <= n; i++) {
      while (n % i == 0) {
        if (i == 2) two++;
        else odd++;
        n /= i;
      }
    }

    if (n != 1) odd++;

    if (!odd) cout << "FastestFinger\n";
    else {
      if (two > 1 || odd > 1) cout << "Ashishgup\n";
      else cout << "FastestFinger\n";
    }
  }

  return 0;
}