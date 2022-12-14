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

  dotc() {
    ll n; int m; cin >> n >> m;
    vector<int> box(63);
    ll sum = 0;
    while (m--) {
      int a; cin >> a;
      sum += a;
      box[__builtin_ctz(a)]++;
    }

    if (sum < n) {
      cout << "-1\n";
      continue;
    }

    int split = 0;
    for (int i = 0; n; i++, n >>= 1) {
      if (n & 1) {
        int j;
        for (j = i; j < 63 && !box[j]; j++)
          ;
        box[j]--;
        split += j - i;
        for (j--; j >= i; j--)
          box[j]++;
      }

      box[i + 1] += box[i] / 2;
    }
    
    cout << split << '\n';
  }

  return 0;
}