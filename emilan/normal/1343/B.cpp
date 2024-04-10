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
#define mp(x, y)  make_pair(x, y);
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second
#define mod       1000000007

using ll = long long;
using vi = vector<int>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

int main() {
  ioThings();

  dotc() {
    int n;
    cin >> n;
    if (n & 3) cout << "NO\n";
    else {
      cout << "YES\n";
      
      for (int i = 0; i < n / 2; i++)
        cout << (i * 2 + 2) << ' ';

      for (int i = 0; i < n / 4; i++)
        cout << (i * 2 + 1) << ' ';
      
      for (int i = n / 4; i < n / 2; i++)
        cout << (i * 2 + 3) << ' ';
        
      cout << '\n';
    }
  }

  return 0;
}